package com.zhou.rabbitmq.simple;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/**
 * 简单模式
 */
public class Producer {
    public static void main(String[] args) {
        // 所有中间件技术都是基于tcp/ip协议基础之上构建新型协议规范，只不过rabbitmq遵循的是amqp协议
        // IP port

        // 1.创建连接工厂
        ConnectionFactory connectionFactory = new ConnectionFactory();
        connectionFactory.setHost("47.119.164.134");
        connectionFactory.setPort(5672);
        connectionFactory.setUsername("admin");
        connectionFactory.setPassword("admin");
        connectionFactory.setVirtualHost("/");
        Connection connection=null;
        Channel channel = null;
        try {
            // 2.创建连接Connection,为什么RabbitMQ是基于通道处理的而不是连接？
            connection = connectionFactory.newConnection("生产者");
            // 3.通过连接获取通道，Channel
            channel = connection.createChannel();
            // 4.通过创建交换机，声明队列，绑定关系，路由key，发送消息和接收消息
            String queueName = "Queue1";
        /*
            参数1：队列名称
            参数2: 是否持久化，非持久化消息会存盘吗？会存盘，但是会随着重启服务器而丢失
            参数3:是否独占队列
            参数4:是否自动删除，随着最后一个消费者消息完毕消息以后是否把队列自动删除
  	        参数5:携带附属属性
        */
            channel.queueDeclare(queueName,false,false,false,null);
            // 5.准备消息内容
            String message = "Hello ,ZhouYingchuan!!!";
            // 6.发送消息给队列，queue
            /*
                参数1: 交换机
                参数2:队列、路由key
                参数3:消息的状态控制
  	            参数4:消息主题
            */
            //面试题：可以存在没有交换机的队列吗？不可能，虽然没有指定交换机但是一定会存在一个默认的交换机
            channel.basicPublish("",queueName,null,message.getBytes());
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            // 7.关闭通道
            if (channel == null && channel.isOpen()){
                try {
                    channel.close();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (TimeoutException e) {
                    e.printStackTrace();
                }
            }
            // 8.关闭连接
            if(connection == null && connection.isOpen()){
                try {
                    connection.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }



    }
}
