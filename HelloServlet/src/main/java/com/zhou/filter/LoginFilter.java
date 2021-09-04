package com.zhou.filter;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class LoginFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws IOException, ServletException {

//        ServletRequest 为HttpServletRequest的父类
        HttpServletRequest request = (HttpServletRequest) req;
        HttpServletResponse response = (HttpServletResponse) resp;
        System.out.println(request.getSession().getAttribute("USER_SESSION"));
        if(request.getSession().getAttribute("USER_SESSION") == null){
            response.sendRedirect("/s1/index.jsp");
        }else {
            response.sendRedirect("/s1/success.jsp");
        }

        chain.doFilter(req,resp);
    }

    @Override
    public void destroy() {

    }
}
