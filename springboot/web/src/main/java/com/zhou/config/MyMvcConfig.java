package com.zhou.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.View;
import org.springframework.web.servlet.ViewResolver;
import org.springframework.web.servlet.config.annotation.ViewControllerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import java.util.Locale;

//如果你想自定义一些功能，只要写这个组件，然后把他交给SpringBoot，SpringBoot就会帮我们自动装配
//扩展 SpringMVC   dispatcherServlet
@Configuration
public class MyMvcConfig implements WebMvcConfigurer {


//    实现视图跳转

    @Override
    public void addViewControllers(ViewControllerRegistry registry) {
        registry.addViewController("/zhou").setViewName("test");
    }


//    ViewResolve 实现了视图解析器接口的类，就可以看做视图解析器

    @Bean
    public ViewResolver myViewResolver(){
        return new MyViewResolver();
    }


//    自定义一个视图解析器，MyViewResolver
    public static class MyViewResolver implements ViewResolver{

    @Override
    public View resolveViewName(String viewName, Locale locale) throws Exception {
        return null;
    }
}

}
