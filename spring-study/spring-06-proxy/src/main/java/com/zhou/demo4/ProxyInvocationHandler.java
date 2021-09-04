package com.zhou.demo4;

import com.zhou.demo3.Rent;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

//用这个类自动动态生成代理类
public class ProxyInvocationHandler implements InvocationHandler {

//    被代理的接口
    private Object target;

    public void setTarget(Object target) {
        this.target = target;
    }

    public ProxyInvocationHandler() {
    }

    //    生成得到的代理类
    public Object getProxy(){
        return Proxy.newProxyInstance(this.getClass().getClassLoader(),target.getClass().getInterfaces(),this);
    }

//    处理代理实例并且返回结果
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
//        动态代理的本质就是使用反射机制实现
        log(method.getName());
        Object result = method.invoke(target, args);
        return result;
    }

    public void log(String msg){
        System.out.println("[Debug] 使用了"+msg+"方法");
    }
}
