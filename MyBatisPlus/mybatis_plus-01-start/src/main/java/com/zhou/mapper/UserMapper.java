package com.zhou.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zhou.pojo.User;
import org.springframework.stereotype.Repository;

//使用MyBatis不需要写mapper.xml文件
//只需要在对应的mapper接口继承BaseMapper类
@Repository  //加上注解，代表是持久层的
public interface UserMapper extends BaseMapper<User> {
//    所有CRUD就已经全部完成，都是MyBatis帮我们做了
//    不需要像MyBatis一样，写一大堆配置
//    继承了所有方法，同时也可以自己写方法
}
