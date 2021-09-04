package com.zhou.config;

import redis.clients.jedis.Jedis;

public class TestPing {
    public static void main(String[] args) {
        // new一个Jedis对象
        Jedis jedis = new Jedis("127.0.0.1", 6379);
        // Jedis中的API就是之前学习的命令
        System.out.println(jedis.ping());

        jedis.close(); //关闭连接
    }
}
