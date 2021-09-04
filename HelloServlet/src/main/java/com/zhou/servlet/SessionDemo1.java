package com.zhou.servlet;

import com.zhou.pojo.Person;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.net.URLEncoder;

public class SessionDemo1 extends HelloServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        解决乱码问题
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        resp.setContentType("text/html");
//        得到Session
        HttpSession session = req.getSession();
//        给Session中存入东西
        session.setAttribute("name", new Person("周迎川",21));
        String name = (String) session.getAttribute("name");
        String sessionId = session.getId();
        if(session.isNew()){
            resp.getWriter().write("Session创建成功"+name+":"+sessionId);
        }else{
            resp.getWriter().write("Session已经存在"+name +":"+sessionId);
        }
//         创建Session的时候，做了哪些操作？
        Cookie cookie = new Cookie("JSESSIONID", sessionId);
        resp.addCookie(cookie);

//        注销Session对象
//        session.removeAttribute("name");//先将session中的数据删除
//        session.invalidate();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
