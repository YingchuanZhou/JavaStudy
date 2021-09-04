package com.zhou.config;

import com.baomidou.mybatisplus.core.injector.ISqlInjector;
import com.baomidou.mybatisplus.extension.injector.LogicSqlInjector;
import com.baomidou.mybatisplus.extension.plugins.OptimisticLockerInterceptor;
import com.baomidou.mybatisplus.extension.plugins.PaginationInterceptor;
import com.baomidou.mybatisplus.extension.plugins.PerformanceInterceptor;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;
import org.springframework.transaction.annotation.EnableTransactionManagement;

//扫描mapper包
@MapperScan("com.zhou.mapper")
//开启事务注解
@EnableTransactionManagement
@Configuration  //代表是配置类
public class MyBatisPlusConfig {

    //    注册乐观锁组件
    @Bean
    public OptimisticLockerInterceptor optimisticLockerInterceptor() {
        return new OptimisticLockerInterceptor();
    }

    //    分页插件
    @Bean
    public PaginationInterceptor paginationInterceptor() {
        return new PaginationInterceptor();
    }

    //    逻辑删除组件
    @Bean
    public ISqlInjector iSqlInjector() {
        return new LogicSqlInjector();
    }

//    导入sql执行效率的插件
    @Bean
    @Profile({"dev", "test"}) //设置dev 和 test环境开启，保证效率
    public PerformanceInterceptor performanceInterceptor() {
        PerformanceInterceptor performanceInterceptor = new PerformanceInterceptor();
//        在工作中常用，如果有慢sql需要优化
        performanceInterceptor.setMaxTime(100);   //ms  设置sql执行的最大时间
        performanceInterceptor.setFormat(true);    //是否格式化代码
        return performanceInterceptor;
    }
}