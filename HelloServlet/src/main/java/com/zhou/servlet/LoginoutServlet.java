package com.zhou.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class LoginoutServlet extends HelloServlet{
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Object user_session = req.getSession().getAttribute("USER_SESSION");
//        System.out.println(user_session);
        if (user_session != null){
            req.getSession().removeAttribute("USER_SESSION");
//            System.out.println(req.getSession().getAttribute("USER_SESSION"));
            resp.sendRedirect("/s1/index.jsp");
        }else{
            resp.sendRedirect("/s1/index.jsp");
        }
    }
}
