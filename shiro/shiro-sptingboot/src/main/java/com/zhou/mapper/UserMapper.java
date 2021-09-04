package com.zhou.mapper;

import com.zhou.pojo.User;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

@Repository
@Mapper //这个注解表示了这是一个mybatis的mapper类
public interface UserMapper {

    public User queryUserByName(String username);

}
