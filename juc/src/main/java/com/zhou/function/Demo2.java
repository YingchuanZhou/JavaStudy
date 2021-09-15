package com.zhou.function;

import java.util.function.Predicate;

/**
 * 断定型接口：有一个输入参数，返回值只能是 布尔值！
 */
public class Demo2 {
    public static void main(String[] args) {
        //判断字符串是否为空
        Predicate<String> predicate = (str)->{return str.isEmpty();};
        System.out.println(predicate.test("11"));
        System.out.println(predicate.test(""));
    }
}