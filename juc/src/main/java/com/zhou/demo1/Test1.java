package com.zhou.demo1;

public class Test1 {

    public static void main(String[] args) {

//        获取CPU核数
//        CPU  密集型   　IO  密集型
        System.out.println(Runtime.getRuntime().availableProcessors());
        new Thread().start();
        
    }
}
