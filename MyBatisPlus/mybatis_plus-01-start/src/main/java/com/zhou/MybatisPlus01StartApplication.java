package com.zhou;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

//配置扫描包，需要扫描接口包
@MapperScan("com.zhou.mapper")
@SpringBootApplication
public class MybatisPlus01StartApplication {

    public static void main(String[] args) {
        SpringApplication.run(MybatisPlus01StartApplication.class, args);
    }

}
