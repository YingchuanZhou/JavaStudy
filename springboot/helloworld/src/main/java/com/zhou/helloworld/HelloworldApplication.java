package com.zhou.helloworld;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

// 本身就是Spring的一个组件

//程序主入口
@SpringBootApplication
//@SpringBootApplication：标注这个类是是一个SpringBoot的应用
public class HelloworldApplication {

    public static void main(String[] args) {
//        将SpringBoot应用启动
        SpringApplication.run(HelloworldApplication.class, args);
    }

}
