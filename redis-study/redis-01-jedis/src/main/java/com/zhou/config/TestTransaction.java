package com.zhou.config;

import com.alibaba.fastjson.JSONObject;
import redis.clients.jedis.Jedis;
import redis.clients.jedis.Transaction;

public class TestTransaction {

    public static void main(String[] args) {
        Jedis jedis = new Jedis("192.168.1.107", 6379);
        jedis.flushDB();
        JSONObject jsonObject = new JSONObject();
        jsonObject.put("name", "xiaohuang");
        jsonObject.put("age", "21");
        jsonObject.put("sex", "boy");
        Transaction multi = jedis.multi(); //  开启事务
        String user = jsonObject.toJSONString();
        try {
            multi.set("user1", user);
            multi.set("user2", user);

            int i = 1/0; //制造异常

            multi.exec();
        } catch (Exception e) {
            multi.discard(); // 出现问题，放弃事务
            e.printStackTrace();
        } finally {
            System.out.println(jedis.mget("user1", "user2"));
            jedis.close(); // 关闭连接
        }
    }
}
