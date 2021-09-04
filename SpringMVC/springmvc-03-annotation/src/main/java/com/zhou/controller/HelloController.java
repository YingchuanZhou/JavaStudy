package com.zhou.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/s3")
public class HelloController {

    @RequestMapping("/hello")
    public String hello(Model model){
        //封装数据
        String result = "Hello,SpringMVCAnnotation!";
        model.addAttribute("msg",result);
        return "hello";//会被视图解析器处理
    }
}
