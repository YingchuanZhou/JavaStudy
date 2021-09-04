package com.zhou.config;

import at.pollux.thymeleaf.shiro.dialect.ShiroDialect;
import org.apache.shiro.spring.web.ShiroFilterFactoryBean;
import org.apache.shiro.web.mgt.DefaultWebSecurityManager;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.HashMap;
import java.util.Map;

@Configuration
public class ShiroConfig {

//    3.ShrioFilterFactoryBean

    @Bean
    public ShiroFilterFactoryBean getShiroFilterFactoryBean(@Qualifier("securityManager") DefaultWebSecurityManager securityManager){
        ShiroFilterFactoryBean shiroFilterFactoryBean = new ShiroFilterFactoryBean();
//        关联DefaultSecurityManager
        shiroFilterFactoryBean.setSecurityManager(securityManager);

//        添加内置过滤器
        /*
            anon：无需认证就可以访问
            authc：必须认证了才能访问
            user：必须拥有  记住我  功能才能用
            perms：拥有对某个资源的权限才能访问
            role：拥有某个角色权限才能访问
         */

//        拦截器实现
        Map<String, String> filterChainDefinitionMap = new HashMap<>();
        filterChainDefinitionMap.put("/user/add","authc");
        filterChainDefinitionMap.put("/user/update","authc");

//        授权，未授权跳转到未授权页面
        filterChainDefinitionMap.put("/user/add","perms[user:add]");
        filterChainDefinitionMap.put("/user/update","perms[user:update]");
        shiroFilterFactoryBean.setFilterChainDefinitionMap(filterChainDefinitionMap);

//        设置登录的请求
        shiroFilterFactoryBean.setLoginUrl("/toLogin");

//        设置未授权请求页面
        shiroFilterFactoryBean.setUnauthorizedUrl("/noauth");
        return shiroFilterFactoryBean;
    }


//    2.DefaultWebSecurityManager

    @Bean(name = "securityManager")
    public DefaultWebSecurityManager getDefaultWebSecurityManager(@Qualifier("userRealm") UserRealm userRealm){
        DefaultWebSecurityManager securityManager = new DefaultWebSecurityManager();
//        关联Realm
        securityManager.setRealm(userRealm);

        return securityManager;
    }


//    1.创建Realm对象，需要自定义，Realm类

    @Bean(name = "userRealm")   //自定义类交给Spring托管
    public UserRealm userRealm(){
        return new UserRealm();
    }


//    整合ShiroDialect：用来整合Shiro和thymeleaf
    public ShiroDialect getShiroDialect(){
        return new ShiroDialect();
    }
}
