package com.zhou.config;

import redis.clients.jedis.Jedis;

public class TestRedis {
        public static void main(String[] args) {
//            所有的API与之前的指令一摸一样，没有一点区别
            Jedis jedis = new Jedis("192.168.1.107", 6379);
            System.out.println(jedis.ping());
            // String
            System.out.println(jedis.set("k1", "v1"));
            System.out.println(jedis.get("k1")); // v1
            System.out.println(jedis.append("k1", "+value"));
            System.out.println(jedis.get("k1")); // v1+value
            System.out.println(jedis.strlen("k1")); // 8
            System.out.println("=====================================================");
            // List
            System.out.println(jedis.lpush("listKey", "l1", "l2", "l3"));
            System.out.println(jedis.lrange("listKey", 0, -1)); // [l3, l2, l1]
            System.out.println(jedis.llen("listKey"));
            System.out.println("=====================================================");
            // Hash
            System.out.println(jedis.hset("hashKey", "k1", "v1"));
            System.out.println(jedis.hset("hashKey", "k2", "v2"));
            System.out.println(jedis.hset("hashKey", "k3", "v3"));
            System.out.println(jedis.hmget("hashKey", "k1", "k2", "k3")); // [v1, v2, v3]
            System.out.println(jedis.hgetAll("hashKey")); // {k3=v3, k2=v2, k1=v1}
            System.out.println("=====================================================");
            // Set
            System.out.println(jedis.sadd("setKey", "s1", "s2", "s3", "s4"));
            System.out.println(jedis.smembers("setKey")); // [s2, s1, s4, s3]
            System.out.println(jedis.scard("setKey"));
            System.out.println("=====================================================");
            // ZSet
            System.out.println(jedis.zadd("ZKey", 90, "z1"));
            System.out.println(jedis.zadd("ZKey", 80, "z2"));
            System.out.println(jedis.zadd("ZKey", 85, "z3"));
            System.out.println(jedis.zrange("ZKey", 0, -1)); // [z2, z3, z1]


            jedis.close(); //关闭连接
    }
}
