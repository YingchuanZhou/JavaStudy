package com.zhou.demo1;

//基本的买票例子

/**
 * 真正的多线程开发，公司中的线程开发,一定要降低耦合
 * 线程就是一个单独的资源类，没有任何的附属操作
 * 1，属性、方法
 *
 */
public class SaleTicketDemo1 {
    public static void main(String[] args) {

//        并发，多个线程操作同一个资源，把资源丢入线程即可
        Ticket ticket  = new Ticket();

//    @FunctionalInterface    Thread 参数为一个函数式接口：JDK1.8之后， lambda表达式，(参数)->{函数体}
        new Thread( () ->{
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

//资源类  OOP思想
class Ticket{
//    属性和方法
    private int num = 50;

//    卖票方式
//    synchronized 本质：队列和锁
    public synchronized void sale(){
        if(num>0){
            System.out.println(Thread.currentThread().getName()+"卖出了"+num--+"票,剩余"+num);
        }
    }
}