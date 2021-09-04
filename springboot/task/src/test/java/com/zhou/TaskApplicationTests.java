package com.zhou;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSenderImpl;
import org.springframework.mail.javamail.MimeMessageHelper;

import javax.mail.MessagingException;
import javax.mail.internet.MimeMessage;
import java.io.File;

@SpringBootTest
class TaskApplicationTests {

    @Autowired
    JavaMailSenderImpl mailSender;


    @Test
    void contextLoads() {
//        一个简单的邮件

        SimpleMailMessage message = new SimpleMailMessage();

        message.setSubject("周迎川你好~");
        message.setText("6666666");

        message.setTo("766623393@qq.com");
        message.setFrom("766623393@qq.com");

        mailSender.send(message);
    }

    @Test
    void contextLoads2() throws MessagingException {
//        一个复杂的邮件

        MimeMessage mimeMessage = mailSender.createMimeMessage();
//        组装
        MimeMessageHelper helper = new MimeMessageHelper(mimeMessage, true);

//        正文
        helper.setSubject("周迎川你好！");
        helper.setText("<h1 style='color:red;'>好好学习</h1>",true);

//        附件
//        helper.addAttachment("1.jpg",new File("C://"));

        helper.setTo("766623393@qq.com");
        helper.setFrom("766623393@qq.com");

        mailSender.send(mimeMessage);
    }
}
