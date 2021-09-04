package com.zhou.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

import static java.lang.System.currentTimeMillis;

public class CookieDemo1 extends HelloServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");

        PrintWriter out = resp.getWriter();
//        Cookie服务器从客户端获取Cookie
        Cookie[] cookies = req.getCookies();
//        判断Cookie是否存在
        if (cookies != null){
            out.write("上次访问的时间是：");

            for (int i = 0; i < cookies.length; i++) {
                Cookie cookie = cookies[i];
//                获取Cookie的名字
                if(cookie.getName() == "lastLoginTime"){//获得cookie的键
//                    获取Cookie中的值
                    long lastLoginTime = Long.parseLong(cookie.getValue());//获得cookie的值
                    Date date = new Date(lastLoginTime);
                    out.write(date.toLocaleString());
                }
            }


        }else{
            out.write("你是第一次访问");
        }
//        服务器给客户端响应一个Cookie
        Cookie lastLoginTime = new Cookie("lastLoginTime", currentTimeMillis()+"");

//        设置Cookie的有效期一天
        lastLoginTime.setMaxAge(24*60*60);
        resp.addCookie(lastLoginTime);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
