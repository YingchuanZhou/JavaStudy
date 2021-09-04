package com.zhou.pojo;

import lombok.Data;

@Data
public class User {
    private String username;
    private String password;
    private String customerNo;

    public User(String username, String password, String customerNo) {
        this.username = username;
        this.password = password;
        this.customerNo = customerNo;
    }
}
