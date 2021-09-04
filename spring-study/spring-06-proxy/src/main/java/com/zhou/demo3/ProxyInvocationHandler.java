package com.zhou.demo3;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

//用这个类自动动态生成代理类
public class ProxyInvocationHandler implements InvocationHandler {

//    被代理的接口
    private Rent rent;

    public void setRent(Rent rent) {
        this.rent = rent;
    }

    public ProxyInvocationHandler() {
    }

    //    生成得到的代理类
    public Object getProxy(){
        return Proxy.newProxyInstance(this.getClass().getClassLoader(),rent.getClass().getInterfaces(),this);
    }

//    处理代理实例并且返回结果
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
//        动态代理的本质就是使用反射机制实现
        seeHouse();
        Object result = method.invoke(rent, args);
        fare();
        return result;
    }

    public void seeHouse(){
        System.out.println("中介看房子");
    }

    public void fare(){
        System.out.println("中介收费");
    }
}
