package com.zhou.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Map;

@RestController
public class JDBCController {

    @Autowired
    JdbcTemplate jdbcTemplate;

//    查询数据库中的所有信息
//    没有实体类也能查询数据库中的数据，使用万能Map
    @GetMapping("/userList")
    public List<Map<String,Object>> userList(){
        String sql = "select * from user";
        List<Map<String, Object>> maps = jdbcTemplate.queryForList(sql);
        return maps;
    }

//    增加用户
    @GetMapping("/addUser")
    public String addUser(){
        String sql = "insert into user values('ZZJ','zzzzzzz','766623393')";
        jdbcTemplate.update(sql);
        return "addUser-ok";
    }

//    修改用户
    @GetMapping("/updateUser/{id}")
    public String updateUser(@PathVariable("id") int id){
        String sql = "update user set password = ? where username="+id;
        Object obj = new Object();
        obj = "cccccccccccccccc";
        jdbcTemplate.update(sql,obj);
        return "updateUser-ok";
    }


//    删除用户
    @GetMapping("/deleteUser/{id}")
    public String deleteUser(@PathVariable("id") int id){
        String sql  = "delete from user where username =?";
        jdbcTemplate.update(sql,id);
        return "deleteUser-ok";
    }
}
