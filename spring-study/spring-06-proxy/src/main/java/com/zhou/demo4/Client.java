package com.zhou.demo4;

import com.zhou.demo2.UserService;
import com.zhou.demo2.UserServiceImpl;

public class Client {
    public static void main(String[] args) {
//        真实角色
        UserServiceImpl userService = new UserServiceImpl();
//代理角色不存在
        ProxyInvocationHandler proxyInvocationHandler = new ProxyInvocationHandler();
        proxyInvocationHandler.setTarget(userService);//设置需要代理的对象
//        动态生成代理类
        UserService proxy = (UserService) proxyInvocationHandler.getProxy();
        proxy.add();

    }
}
