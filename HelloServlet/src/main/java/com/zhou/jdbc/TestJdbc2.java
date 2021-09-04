package com.zhou.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class TestJdbc2 {

    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        //        配置信息
        String url = "jdbc:mysql://localhost:3306/commodity?useUnicode=true&characterEncoding=utf-8 ";
        String username = "root";
        String password = "zyc766623393";

//        注册驱动
        Class.forName("com.mysql.cj.jdbc.Driver");

//       获取数据库连接对象
        Connection connection = DriverManager.getConnection(url, username, password);

//        定义sql
        String sql = "insert into users(username,password,commodity) values (?,?,?)";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        int i = preparedStatement.executeUpdate();
        if(i>0){
            System.out.println("插入成功");
        }else{
            System.out.println("插入失败");
        }

//        关闭数据连接
        preparedStatement.close();
        connection.close();
    }
}
