package com.zhou.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.Arrays;

@Controller
public class TestController {

    @RequestMapping("/t1")
    public String test(Model model){
        //存入数据
        model.addAttribute("msg","<h1>Hello,SpringBoot</h1>");
        model.addAttribute("users", Arrays.asList("Zyc","Zj"));
        //classpath:/templates/test.html
        return "test";
    }
}
