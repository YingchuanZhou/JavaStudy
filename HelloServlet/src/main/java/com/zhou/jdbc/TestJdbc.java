package com.zhou.jdbc;

import java.sql.*;

public class TestJdbc {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
//        配置信息
        String url = "jdbc:mysql://localhost:3306/commodity?useUnicode=true&characterEncoding=utf-8 ";
        String username = "root";
        String password = "zyc766623393";

//        1.加载数据库驱动

        Class.forName("com.mysql.cj.jdbc.Driver");
//        2.获取数据库连接对象
        Connection connection = DriverManager.getConnection(url, username, password);
//        3. 获取执行sql的对象
        Statement statement = connection.createStatement();
//        4. 编写sql
        String sql = "select * from user";
//        5. 执行sql
        ResultSet resultSet = statement.executeQuery(sql);
        while(resultSet.next()){
            System.out.println(resultSet.getString("username")+
                                resultSet.getString("password")+
                                resultSet.getString("customer_no"));
        }
//        6.关闭连接，释放资源，先开后关

        resultSet.close();
        statement.close();
        connection.close();

    }
}