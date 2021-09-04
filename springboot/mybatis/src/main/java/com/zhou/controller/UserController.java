package com.zhou.controller;

import com.zhou.mapper.UserMapper;
import com.zhou.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class UserController {

    @Autowired
    private UserMapper userMapper;

//    查询
    @GetMapping("/queryUserList")
    public List<User> queryUserList(){
        List<User> userList = userMapper.queryUserList();
        for (User user : userList) {
            System.out.println(user);
        }
        return userList;
    }

//    通过用户名查询
    public User queryUserById(){
        return userMapper.queryUserById("zyc");
    }

//    添加用户
    public String addUser(){
        int i = userMapper.addUser(new User("zzz", "123124214", "766623393"));
        if(i>0){
            return "ok";
        }else{
            return "fail";
        }
    }

//    修改
    public String updateUser(){
        int i = userMapper.updateUser(new User("zyc", "123213", "766623393"));
        if(i>0){
            return "ok";
        }else{
            return "fail";
        }
    }
//    删除
    public String deleteUser(){
        int i = userMapper.deleteUser("zyc");
        if(i>0){
            return "ok";
        }else{
            return "fail";
        }
    }
}
