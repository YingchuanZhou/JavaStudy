package com.zhou.filter;

import javax.servlet.*;
import java.io.IOException;

public class CharacterEncodingFilter  implements Filter {
//    初始化，web服务器启动时就初始化，因为必须在服务器启动之后就要开始监听过滤
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        System.out.println("过滤器初始化");
    }

    /*
    1. 过滤器中所有代码，在过滤请求的时候都会执行
    2. 必须要让过滤器继续通行
     */
//    chain链
    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=UTF-8");

        System.out.println("过滤器执行前");
        chain.doFilter(request,response);//让程序请求继续走，如果不写，则程序到这里就被拦截停止了
        System.out.println("过滤器执行后");
    }

//    销毁,服务器关闭的时候就会销毁
    @Override
    public void destroy() {

        System.out.println("过滤器销毁");
    }
}
