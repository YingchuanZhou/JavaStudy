package com.zhou.diy;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.Signature;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;

//使用注解方式实现AOP
@Aspect//标记这个类是一个切面
public class AnnotationPointCut {

    @Before("execution(* com.zhou.diy.AnnotationPointCut.*(..))")
    public void before(){
        System.out.println("======方法执行前=======");
    }

    @After("execution(* com.zhou.diy.AnnotationPointCut.*(..))")
    public void after(){
        System.out.println("======方法执行后=======");
    }

//在环绕增强中，我们可以给定一个参数，代表我们要获取处理切入的点
    @Around("execution(* com.zhou.diy.AnnotationPointCut.*(..))")
    public void around(ProceedingJoinPoint joinPoint) throws Throwable {
        System.out.println("环绕前");
        Signature signature = joinPoint.getSignature();//获得签名
        System.out.println(signature);
//        执行方法
        joinPoint.proceed();

        System.out.println("环绕后");
    }
}
