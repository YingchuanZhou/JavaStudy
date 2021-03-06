package com.zhou.service;

import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

@Service
public class ScheduledService {

//    在特定的时间执行该方法  Timer
//    Cron表达式
//    秒  分  时  日  月  星期
    @Scheduled(cron = "0 * * * * 0-7")
    public void hello(){
        System.out.println("hello,你被执行了~");
    }
}
