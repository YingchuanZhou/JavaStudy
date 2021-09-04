package com.zhou.config;

import com.zhou.pojo.User;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;

//这个也会被Spring容器托管，注册到容器中，因为本身就是一个@Component
//@Configuration 代表这是一个配置类和之前的beans.xml差不多
@Configuration
//声明扫描包
@ComponentScan("com.zhou.pojo")
//如果有多个bean，将多个bean导入
@Import(MyConfig2.class)
public class MyConfig {

//    注册一个bean，就相当于我们之前写的一个bean标签
//    这个方法的名字就相当于bean标签中的id属性
//    这个方法的返回值就相当于bean标签的class属性
    @Bean
    public User getUser(){
        return  new User();//就是返回要注入bean的对象
    }
}
