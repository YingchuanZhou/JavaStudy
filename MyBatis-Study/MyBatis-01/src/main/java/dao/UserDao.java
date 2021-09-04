package dao;

import pojo.User;

import java.util.List;
import java.util.Map;

public interface UserDao {
    List<User> getUserList();
    List<User> getUserByLike(String value);
    User getUserById(String username);
    int addUser(User  user);
    int addUser2(Map<String,Object> map);
    int updateUser(User user);
    int deleteUser(String username);
}
