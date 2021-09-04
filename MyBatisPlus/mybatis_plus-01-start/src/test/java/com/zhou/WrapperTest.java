package com.zhou;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zhou.mapper.UserMapper;
import com.zhou.pojo.User;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@SpringBootTest
public class WrapperTest {
    @Autowired
    private UserMapper userMapper;

    @Test
    void contextLoads(){
//         查询name不为空，email不为空，年龄大于12
        QueryWrapper<User> wrapper = new QueryWrapper<>();
        wrapper.isNotNull("name")
                .isNotNull("email")
                .ge("age",12);
//        与之前的map类似
        List<User> users= userMapper.selectList(wrapper);
        users.forEach(System.out::println);
    }
    @Test
    void test2(){
//        查询id为1的
        QueryWrapper<User> wrapper = new QueryWrapper<>();
        wrapper.eq("id",1);
        User user = userMapper.selectOne(wrapper);
        System.out.println(user);
    }

    @Test
    void test3(){
//        查询年龄在20-30岁的人数
        QueryWrapper<User> wrapper = new QueryWrapper<>();
        wrapper.between("age",20,30);
        Integer count = userMapper.selectCount(wrapper);
        System.out.println(count);
    }

//    模糊查寻
    @Test
    void test4(){
        QueryWrapper<User> wrapper = new QueryWrapper<>();
//        没有e
        wrapper.notLike("name","e")
                .likeRight("email","t");    //t%
        List<Map<String, Object>> maps = userMapper.selectMaps(wrapper);
        maps.forEach(System.out::println);
    }
//    模糊查询
    @Test
    void test5(){
        QueryWrapper<User> wrapper = new QueryWrapper<>();
//        id在子查询中查出，就是in查询
        wrapper.inSql("id","select id from where id < 3");

        List<Object> objects = userMapper.selectObjs(wrapper);
        objects.forEach(System.out::println);
    }

    //    排序
    @Test
    void test6() {
        QueryWrapper<User> wrapper = new QueryWrapper<>();
//        通过id排序
        wrapper.orderByDesc("id");

        List<User> users = userMapper.selectList(wrapper);
        users.forEach(System.out::println);
    }

}
