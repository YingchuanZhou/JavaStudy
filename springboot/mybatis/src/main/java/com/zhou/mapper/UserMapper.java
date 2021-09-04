package com.zhou.mapper;

import com.zhou.pojo.User;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

//这个注解表示这是一个mybatis的mapper接口类
//或者去主程序中添加   @MapperScan("com.zhou.mapper")
@Mapper
@Repository
public interface UserMapper {

    List<User> queryUserList();

    User queryUserById(String username);

    int addUser(User user);

    int updateUser(User user);

    int deleteUser(String username);

}
