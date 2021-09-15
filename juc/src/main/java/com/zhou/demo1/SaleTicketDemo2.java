package com.zhou.demo1;

//基本的买票例子

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * 真正的多线程开发，公司中的线程开发,一定要降低耦合
 * 线程就是一个单独的资源类，没有任何的附属操作
 * 1，属性、方法
 *
 */
public class SaleTicketDemo2 {
    public static void main(String[] args) {

//        并发，多个线程操作同一个资源，把资源丢入线程即可
        Ticket2 ticket  = new Ticket2();

//    @FunctionalInterface    Thread 参数为一个函数式接口：JDK1.8之后， lambda表达式，(参数)->{函数体}
        new Thread(()->{
            for (int i = 0; i < 50; i++) {
                ticket.sale();
            }
        },"A").start();
        new Thread(() ->{
            ticket.sale();
        },"B").start();
        new Thread(()->{
            ticket.sale();
        },"C").start();
    }
}

//Lock三部曲
//1.new ReentrantLick()
//2.加锁  lock.lock()
//3.finally  ==>  lock.unlock  解锁
class Ticket2{
    //    属性和方法
    private int num = 50;
    Lock lock  = new ReentrantLock();
    public  void sale(){
        lock.lock();
        try {
//            业务代码
            if(num>0){
                System.out.println(Thread.currentThread().getName()+"卖出了"+num--+"票,剩余"+num);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            lock.unlock();//解锁
        }

    }
}