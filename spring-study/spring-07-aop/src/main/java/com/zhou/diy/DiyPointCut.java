package com.zhou.diy;

//自定义方式实现AOP
public class DiyPointCut {

    public void before(){
        System.out.println("======方法执行前=======");
    }

    public void after(){
        System.out.println("======方法执行后=======");
    }
}
