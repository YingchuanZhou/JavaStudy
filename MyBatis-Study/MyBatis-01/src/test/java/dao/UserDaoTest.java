package dao;

import org.apache.ibatis.session.SqlSession;
import org.junit.Test;
import pojo.User;
import utils.MyBatisUtil;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class UserDaoTest {

    @Test
    public void test(){

        //1.获取sqlSession对象
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        //2.执行sql,方式1：getMapper
        UserDao userDao = sqlSession.getMapper(UserDao.class);
        List<User> userList = userDao.getUserList();

        //方式2：
        List<User> users = sqlSession.selectList("dao.UserDao.getUserList");

        for (User user : userList) {
            System.out.println(user);
        }
        //关闭sqlSession
        sqlSession.close();
        //

    }

    @Test
    public void test2(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserDao mapper = sqlSession.getMapper(UserDao.class);
        User userById = mapper.getUserById("766623393");
        System.out.println(userById);
        sqlSession.close();
    }

    @Test
    public void test3(){
        //1.获取sqlSession对象
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        //2.执行sql,方式1：getMapper
        UserDao userDao = sqlSession.getMapper(UserDao.class);

        List<User> userList = userDao.getUserByLike("Z%");
        for (User user : userList) {
            System.out.println(user);
        }
        //关闭sqlSession
        sqlSession.close();
        //
    }

    @Test
    public void addUser(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserDao mapper = sqlSession.getMapper(UserDao.class);
        int zyc = mapper.addUser(new User("zyc", "123", "4"));
        if (zyc>0)
            System.out.println("1111");
        sqlSession.commit();//提交事务，增加删除修改都需要提交事务
        sqlSession.close();
    }

    @Test
    public void addUser2(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserDao mapper = sqlSession.getMapper(UserDao.class);
        Map<String, Object> map = new HashMap<>();
        map.put("userName","ZengJing");
        map.put("PassWord","123456");
        map.put("customerNo","766623393");
        int i = mapper.addUser2(map);
        if (i>0)
            System.out.println("111");
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void updateTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserDao mapper = sqlSession.getMapper(UserDao.class);
        int i = mapper.updateUser(new User("766623393", "123456", "2"));
        if(i>0)
            System.out.println("1111");
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void deleteTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserDao mapper = sqlSession.getMapper(UserDao.class);
        int i = mapper.deleteUser("766623393");
        if (i>0)
            System.out.println("1111");
        sqlSession.commit();
        sqlSession.close();
    }
}
