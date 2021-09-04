package com.zhou.service;

import com.zhou.pojo.User;
import org.springframework.stereotype.Service;

@Service
public interface UserService {
    public User queryUserByName(String username);
}
