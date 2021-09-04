package com.zhou.servlet;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class HelloServlet extends HttpServlet {

//    由于get或者post只是请求实现的方式不同，可以相互调用，业务逻辑都一样
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        ServletOutputStream outputStream = resp.getOutputStream();
        resp.setContentType("text/html");
        resp.setCharacterEncoding("utf-8");
        PrintWriter writer = resp.getWriter();//响应流
        writer.println("Hello, Servlet！！！");

//        this.getInitParameter()   初始化参数
//        this.getServletConfig();  Servlet 配置
//        this.getServletContext()  Servlet 上下文

        ServletContext servletContext = this.getServletContext();
        String username = "周迎川";
        servletContext.setAttribute("username",username);//存入键值对

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
