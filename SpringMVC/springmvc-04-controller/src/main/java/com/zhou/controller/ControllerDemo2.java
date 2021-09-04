package com.zhou.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller//代表这个类会被Spring接管
//加了该注解的类，如果类中所有的方法返回值都是String，并且有具体页面可以跳转，那么就会被视图解析器解析
public class ControllerDemo2 {

    @RequestMapping("/t2")
    public String test2(Model model){
        model.addAttribute("msg","ControllerDemo2");
        return "test1";
    }
}
