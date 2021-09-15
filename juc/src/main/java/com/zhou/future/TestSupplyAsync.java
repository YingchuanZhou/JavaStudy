package com.zhou.future;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;

public class TestSupplyAsync {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        //有返回值的异步回调
        CompletableFuture<Integer> completableFuture=CompletableFuture.supplyAsync(()->{
            System.out.println(Thread.currentThread().getName());
            try {
                TimeUnit.SECONDS.sleep(2);
                int i=1/0;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return 1024;
        });
        System.out.println(completableFuture.whenComplete((t, u) -> {
            //success 回调
            System.out.println("t=>" + t); //正常的返回结果
            System.out.println("u=>" + u); //抛出异常的 错误信息
        }).exceptionally((e) -> {
            //error回调
            System.out.println(e.getMessage());
            return 404;
        }).get());
    }
}
