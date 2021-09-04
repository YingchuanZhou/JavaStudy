package com.zhou;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zhou.mapper.UserMapper;
import com.zhou.pojo.User;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

@SpringBootTest
class MybatisPlus01StartApplicationTests {

    @Autowired
    private UserMapper userMapper;

    @Test
    void contextLoads() {
//        参数是一个Wrapper，条件构造器，这里先使用null
        List<User> userList = userMapper.selectList(null); //查询全部user
        userList.forEach(System.out::println);
    }

//    测试插入
    @Test
    public void testInsert(){
        User user = new User();
        user.setAge(21);
        user.setName("zyc");
        user.setEmail("766623393@qq.com");  //自动生成id
        int res = userMapper.insert(user);  //返回影响行数
        System.out.println(res);    //发现id自动生成
    }

//    测试更新
    @Test
    public void testUpdate(){
        User user = new User();
        user.setAge(18);
        user.setName("ZJ");
        user.setEmail("766623393@qq.com");
//        会自动生成sql，会根据字段自动匹配
        int res = userMapper.updateById(user);  //注意这个参数是一个对象
        System.out.println(res);    //返回影响行数
    }


//    测试乐观锁成功
    @Test
    public void testOptimisticLocker(){
//        查询用户信息
        User user = userMapper.selectById(1L);
//        修改用户信息
        user.setName("ZYC");
        user.setEmail("766623393@qq.com");
//        执行更新操作
        userMapper.updateById(user);

    }

    //    测试乐观锁失败，模拟多线程下
    @Test
    public void testOptimisticLocker2() {
//        线程1
//        查询用户信息
        User user = userMapper.selectById(1L);
//        修改用户信息
        user.setName("ZYC111");
        user.setEmail("766623393@qq.com");

//        线程2
//        查询用户信息
        User user2 = userMapper.selectById(1L);
//        修改用户信息
        user2.setName("ZYC222");
        user2.setEmail("766623393@qq.com");
//        线程2执行更新操作
        userMapper.updateById(user2);

//        线程1执行更新操作
//        如果想数据库中的值是第一次的值，可以使用自旋锁，多次尝试提交
        userMapper.updateById(user);  //如果没有乐观锁，线程1的值会覆盖线程2的值

    }

//    测试查询
    @Test
    public void testSelect(){
//        查询一个
        User user = userMapper.selectById(1L);
        System.out.println(user);
//        查询多个
        List<User> users = userMapper.selectBatchIds(Arrays.asList(1L, 2L, 3L));
        users.forEach(System.out::println);
    }

//    条件查询 map
    @Test
    public void testSelectByIf(){
        HashMap<String, Object> map = new HashMap<>();
//        设置要查询的条件
        map.put("name","zyc");
//        可以多条件
        map.put("age",21);
        List<User> users = userMapper.selectByMap(map);
        users.forEach(System.out::println);
    }

//    分页测试
    public void testPage(){
//        参数一：当前页
//        参数二：页面大小
//        使用了分页插件之后，所有的分页也变得简单
        Page<User> userPage = new Page<>(1,5);
        userMapper.selectPage(userPage,null);

        userPage.getRecords().forEach(System.out::println);
//        获取总数
        System.out.println(userPage.getTotal());
    }

//    测试删除
    @Test
    public void testDelete(){
//        通过id删除
        userMapper.deleteById(1L);
//        批量删除
        userMapper.deleteBatchIds(Arrays.asList(1L,2L,3L));
//        通过map删除
        HashMap<String, Object> map = new HashMap<>();
//        删除名字是zyc的
        map.put("name","zyc");
        userMapper.deleteByMap(map);
    }

    //    测试逻辑删除
    @Test
    public void testDeleteLogic(){
//        通过id删除
        userMapper.deleteById(1L);
    }
}
