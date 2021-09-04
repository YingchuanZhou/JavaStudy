package com.zhou.swaggerdemo.controller;


import com.zhou.swaggerdemo.entity.User;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;


@RestController
public class HelloController {

//    还有一个请求时/error
    @GetMapping("/hello")
    //接口放在方法上，不是在类上
    @ApiOperation("Hello方法")
    public String hello(@ApiParam("用户名") String username){
        return "hello"+username;
    }

//    只要在接口中，返回值存在的实体类都会被扫描到Swagger中
    @PostMapping("/user")
    public User user(){
        return new User();
    }
}
