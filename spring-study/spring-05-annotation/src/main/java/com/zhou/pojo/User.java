package com.zhou.pojo;


import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;


//等价于    <bean id="user" class="com.zhou.pojo.User"/>
//@Component  组件
@Component
@Scope("singleton")
public class User {

//    相当于 <property name="name" value="周迎川"/>
    @Value("周迎川")
    public String name ;


//    该注解也可以用在Set方法上面
    @Value("周迎川2")
    public void setName(String name) {
        this.name = name;
    }
}
