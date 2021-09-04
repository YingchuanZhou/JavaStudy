package com.zhou.mapper;

import com.zhou.pojo.User;

import java.util.List;

public interface UserMapper {
    List<User> selectUsers();
    int addUser(User user);
    int deleteUser(String username);
}
