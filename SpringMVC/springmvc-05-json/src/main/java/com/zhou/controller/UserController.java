package com.zhou.controller;

import com.alibaba.fastjson.JSON;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.zhou.pojo.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

//该注解会默认走视图解析器，如果想返回String，需要在方法上加一个@ResponseBody注解
//@Controller
//该注解会默认返回字符串
@RestController
public class UserController {

//    @RequestMapping(value = "/j1",produces = "text/plain;charset=UTF-8")//解决乱码
    @RequestMapping("/j1")
    //@ResponseBody   //加该注解之后，不会走视图解析器会直接返回字符串
    public String json1() throws JsonProcessingException {
        //Jackson   ObjectMapper
        ObjectMapper mapper = new ObjectMapper();

        //创建一个对象
        User user = new User("周迎川", 21, "男");

        String str = mapper.writeValueAsString(user);
        return str;
    }

    @RequestMapping("/j2")
    public String json2() throws JsonProcessingException {
        ObjectMapper mapper = new ObjectMapper();
        List<User> userList = new ArrayList<>();
        User user = new User("周迎川", 21, "男");
        User user2 = new User("周迎川2", 21, "男");
        User user3 = new User("周迎川3", 21, "男");
        User user4 = new User("周迎川4", 21, "男");

        userList.add(user);
        userList.add(user2);
        userList.add(user3);
        userList.add(user4);

        String str = mapper.writeValueAsString(userList);
        return str;
    }

    @RequestMapping("/j3")
    public String json3() throws JsonProcessingException {
//        使用java格式化日期输出
        ObjectMapper mapper = new ObjectMapper();
        Date date = new Date();
//        自定义日期格式
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
//        ObjectMapper，时间解析后的默认格式是Timestamp：时间戳
        String str = mapper.writeValueAsString(simpleDateFormat.format(date));
        return str;
    }

    @RequestMapping("/j4")
    public String json4() throws JsonProcessingException {
//        使用jackson格式化日期输出
        ObjectMapper mapper = new ObjectMapper();
//        不使用时间戳
        mapper.configure(SerializationFeature.WRITE_DATE_KEYS_AS_TIMESTAMPS,false);
//        自定义日期格式
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        mapper.setDateFormat(simpleDateFormat);
        Date date = new Date();
//        ObjectMapper，时间解析后的默认格式是Timestamp：时间戳
        String str = mapper.writeValueAsString(date);
        return str;
    }

    @RequestMapping("/j5")
    public String json5() throws JsonProcessingException {

        List<User> userList = new ArrayList<>();
        User user = new User("周迎川", 21, "男");
        User user2 = new User("周迎川2", 21, "男");
        User user3 = new User("周迎川3", 21, "男");
        User user4 = new User("周迎川4", 21, "男");

        userList.add(user);
        userList.add(user2);
        userList.add(user3);
        userList.add(user4);

        String str = JSON.toJSONString(userList);
        return str;
    }
}
