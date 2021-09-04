package com.zhou.service;

import org.springframework.stereotype.Service;

@Service
public class AsyncService {

    public void hello() throws InterruptedException {
        Thread.sleep(3000);
        System.out.println("业务正在进行中......");
    }
}
