package com.zhou.pool;

import java.util.concurrent.*;

public class Demo2 {

    public static void main(String[] args) {

        ThreadPoolExecutor threadPool = new ThreadPoolExecutor(
                2,
                5,
                3,
                TimeUnit.SECONDS,
                new LinkedBlockingDeque<>(3),
                Executors.defaultThreadFactory(),
//                new ThreadPoolExecutor.AbortPolicy()  //该拒绝策略为：银行满了，还有人进来，不处理这个人的，并抛出异常
//                new ThreadPoolExecutor.CallerRunsPolicy()  //该拒绝策略为：哪来的去哪里 main线程进行处理
//                new ThreadPoolExecutor.DiscardPolicy()   //该拒绝策略为：队列满了,丢掉异常，不会抛出异常。
                new ThreadPoolExecutor.DiscardOldestPolicy()   //该拒绝策略为：队列满了，尝试去和最早的进程竞争，不会抛出异常
        );

        //线程池用完必须要关闭线程池
        try {

            for (int i = 1; i <=100 ; i++) {
                //通过线程池创建线程
                threadPool.execute(()->{
                    System.out.println(Thread.currentThread().getName()+ " ok");
                });
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            threadPool.shutdown();
        }
    }
}
