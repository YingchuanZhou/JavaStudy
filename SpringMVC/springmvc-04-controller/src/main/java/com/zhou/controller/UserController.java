package com.zhou.controller;

import com.zhou.pojo.User;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
@RequestMapping("/user")
public class UserController {

//    localhost:8080/user/t1?name=xxx
//    前端接收一个参数
    @GetMapping("/t1")
//    指定参数名必须为name
    public String test1(@RequestParam("name") String name, Model model){
//        1.接收前端参数
        System.out.println("接收到的参数："+name);
//        2.将结果返回给前端，Model
        model.addAttribute("msg",name);
//        3.视图跳转
        return "test1";
    }

//    前端接收一个User对象
    /*
        1. localhost:8080/user/t2?id=1&name=zhouyingchuan&age=21
            1. 接收前端传递的参数，判断参数的名字，假设名字直接在方法上，可以直接使用
            2. 假设传递的是一个对象，则匹配对象中的字段名称，如果一致，则成功，不一致则失败
     */
    @GetMapping("/t2")
    public String test2(User user){
        System.out.println(user);
        return "test1";
    }

    @GetMapping("t3")
    public String test3(){
        return "test1";
    }
}
