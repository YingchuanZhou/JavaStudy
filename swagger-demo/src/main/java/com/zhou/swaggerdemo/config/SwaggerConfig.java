package com.zhou.swaggerdemo.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.env.Environment;
import org.springframework.core.env.Profiles;
import org.springframework.stereotype.Controller;
import springfox.documentation.RequestHandler;
import springfox.documentation.builders.PathSelectors;
import springfox.documentation.builders.RequestHandlerSelectors;
import springfox.documentation.service.ApiInfo;
import springfox.documentation.service.Contact;
import springfox.documentation.spi.DocumentationType;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2;

import java.util.ArrayList;

@Configuration
@EnableSwagger2   //开启swagger2
public class SwaggerConfig {


    @Bean
    public Docket docket1(){
        return new Docket(DocumentationType.SWAGGER_2).groupName("A");
    }
    @Bean
    public Docket docket2(){
        return new Docket(DocumentationType.SWAGGER_2).groupName("B");
    }
    @Bean
    public Docket docket3(){
        return new Docket(DocumentationType.SWAGGER_2).groupName("C");
    }
    @Bean
    public Docket docket4(){
        return new Docket(DocumentationType.SWAGGER_2).groupName("D");
    }


//    配置Swagger的Docket的Bean实例
    @Bean
    public Docket docket(Environment environment){

//        设置要显示的Swagger环境
        Profiles profiles = Profiles.of("dev", "test");
//        通过environment.acceptsProfiles判断当前是否处于设定的环境中
        boolean flag = environment.acceptsProfiles(profiles);


        return new Docket(DocumentationType.SWAGGER_2)
                .apiInfo(apiInfo())
                .enable(flag)//enable是否启动Swagger，如果为false，Swagger不能在浏览器中访问
                .groupName("周迎川")
                .select()
                //RequestHandlerSelectors，配置要扫描接口的方式
                //basePackage()：指定要扫的包
                //any()：扫描全部
                //none()：不扫描
                //withClassAnnotation：扫描类上的注解，参数是一个注解反射对象
                //withMethodAnnotation：扫描方法上的注解
//                .apis(RequestHandlerSelectors.withClassAnnotation(Controller.class))
                .apis(RequestHandlerSelectors.basePackage("com.zhou.swaggerdemo.controller"))
//                paths() 过滤什么路径,将指定路径的过滤掉
//                .paths(PathSelectors.ant("/zhou/**"))
                .build();
    }

//    配置Swagger的信息=>apiInfo
    private ApiInfo apiInfo(){

        Contact contact = new Contact("周迎川", "https://www.baidu.com", "766623393@qq.com");
        return new ApiInfo(
                "周迎川的API文档",
                "我无敌你随意",
                "1.0",
                "https://www.baidu.com",
                contact,
                "Apache 2.0",
                "http://www.apache.org/licenses/LICENSE-2.0",
                new ArrayList());
    }
}
