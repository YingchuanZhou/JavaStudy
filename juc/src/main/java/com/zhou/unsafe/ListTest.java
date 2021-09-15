package com.zhou.unsafe;

import java.util.*;
import java.util.concurrent.CopyOnWriteArrayList;


//java.util.ConcurrentModificationException 并发修改异常！
public class ListTest {

    public static void main(String[] args) {
//      并发下,ArrayList不安全,会造成并发修改异常
        /**
         * 解决方案:
         * 1.List<Object> arrayList = new Vector<>();Vector本身就是安全的
         * 2.List<Object> arrayList = Collections.synchronizedList(new ArrayList<>());
         * 3.List<Object> arrayList = new CopyOnWriteArrayList<>();
         */

//        CopyOnWriteArrayList：写入时复制！ COW 计算机程序设计领域的一种优化策略
//        多个线程调用的时候，list，读取的时候，固定的，写入（存在覆盖操作）；在写入的时候避免覆盖，造成数据错乱的问题；
//        读写分离

//        List<Object> arrayList = new ArrayList<>();
//        List<Object> arrayList = new Vector<>();
//        List<Object> arrayList = Collections.synchronizedList(new ArrayList<>());
        List<Object> arrayList = new CopyOnWriteArrayList<>();

        for(int i=1;i<=10;i++){
            new Thread(()->{
                arrayList.add(UUID.randomUUID().toString().substring(0,5));
                System.out.println(arrayList);
            },String.valueOf(i)).start();
        }

    }
}
