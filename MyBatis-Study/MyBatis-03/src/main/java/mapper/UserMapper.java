package mapper;

import org.apache.ibatis.annotations.*;
import pojo.User;

import java.util.List;
import java.util.Map;

public interface UserMapper {

    @Select("select * from commodity.user")
    List<User> getUserList();

    @Select("select * from user where id = #{uid")
    User getUserById(@Param("uid") int id);

    @Insert("insert into user (id,name,password) values (#{id},#{name},#{password})")
    int addUser(User user);

    @Update("update user set name = #{name},password = #{password} where id = #{id}")
    int updateUser(User user);

    @Delete("delete from user where id = #{uid")
    int deleteUser(@Param("uid") int id);
}
