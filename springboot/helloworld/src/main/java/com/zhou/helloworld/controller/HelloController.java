package com.zhou.helloworld.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//原理：自动装配
@RestController
public class HelloController {

//    接口：localhost:8080/hello
    @RequestMapping("/hello")
    public String hello(){
//        调用业务，接收前端参数
        return "hello,world";
    }
}
