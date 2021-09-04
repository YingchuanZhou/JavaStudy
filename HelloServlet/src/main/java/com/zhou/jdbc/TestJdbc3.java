package com.zhou.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class TestJdbc3 {

    public static void main(String[] args) {
        Connection connection = null;
        //        配置信息
        String url = "jdbc:mysql://localhost:3306/commodity?useUnicode=true&characterEncoding=utf-8";
        String username = "root";
        String password = "zyc766623393";

//        注册驱动
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            //       获取数据库连接对象
            connection = DriverManager.getConnection(url, username, password);
//       开启事务
            connection.setAutoCommit(false);

//        定义sql
            String sql = "insert into users(username,password,commodity) values (?,?,?)";
            PreparedStatement preparedStatement = connection.prepareStatement(sql);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
//        关闭数据连接
        try {
            connection.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }
}
