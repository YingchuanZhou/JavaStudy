package mapper;

import pojo.User;

import java.util.List;
import java.util.Map;

public interface UserMapper {
    List<User> getUserList();
    User getUserById(String username);
    int addUser(User  user);
    int updateUser(User user);
    int deleteUser(String username);
    List<User> getUserByLimit(Map<String,Integer> map);
    List<User> getUserByRowBounds();
}
