package com.zhou.controller;


import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@Controller
public class ModelTest1 {

    @RequestMapping("/m1/t1")
//    可以通过request和response转发或者重定向
    public String test1(HttpServletRequest request, HttpServletResponse response){
        HttpSession session = request.getSession();
        System.out.println(session.getId());
        return "test1";
    }

    @RequestMapping("/m1/t11")
//    可以通过request和response转发或者重定向
    public void test11(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.sendRedirect("/index.jsp");
    }

    @RequestMapping("/m1/t12")
//    可以通过request和response转发或者重定向
    public void test12(HttpServletRequest request, HttpServletResponse response){
        request.getRequestDispatcher("/index.jsp");
    }


    @RequestMapping("/m1/t2")
//    有视图解析器
    public String test2(Model model){
        model.addAttribute("msg","ModelTest1");
        return "test1";
    }


//    没有视图解析器
    @RequestMapping("/m1/t3")
    public String test3(Model model){
//        转发
        model.addAttribute("msg","ModelTest1");
        return "forward:/WEB-INF/jsp/test1.jsp";
    }

    @RequestMapping("/m1/t4")
    public String test4(Model model){
//        重定向
        model.addAttribute("msg","ModelTest1");
        return "redirect:/index.jsp";
    }

}
