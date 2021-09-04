package com.zhou.demo1;

//客户
public class Client {

    public static void main(String[] args) {
//        房东要出租房子
        Host host1 = new Host();
//代理帮助房东出租房子，并且还有一些附属操作
        Proxy proxy = new Proxy(host1);
//        不需要找房东，直接找代理也能租到房东的房子
        proxy.rent();
    }

}
