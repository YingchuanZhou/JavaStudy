package mapper;

import org.apache.ibatis.session.RowBounds;
import org.apache.ibatis.session.SqlSession;
import org.apache.log4j.Logger;
import org.junit.Test;
import pojo.User;
import utils.MyBatisUtil;

import java.util.HashMap;
import java.util.List;

public class UserMapperTest {

    static Logger logger = Logger.getLogger(UserMapperTest.class);

    @Test
    public void test(){

        //1.获取sqlSession对象
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        //2.执行sql,方式1：getMapper
        UserMapper UserMapper = sqlSession.getMapper(UserMapper.class);
        List<User> userList = UserMapper.getUserList();
//
//        //方式2：
//        List<User> users = sqlSession.selectList("dao.UserMapper.getUserList");

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
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        User userById = mapper.getUserById("766623393");
        System.out.println(userById);
        sqlSession.close();
    }


    @Test
    public void addUser(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        int zyc = mapper.addUser(new User("zyc", "123", "4"));
        if (zyc>0)
            System.out.println("1111");
        sqlSession.commit();//提交事务，增加删除修改都需要提交事务
        sqlSession.close();
    }
    

    @Test
    public void updateTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        int i = mapper.updateUser(new User("766623393", "123456", "2"));
        if(i>0)
            System.out.println("1111");
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void deleteTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        int i = mapper.deleteUser("766623393");
        if (i>0)
            System.out.println("1111");
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void testLog4j(){
        logger.info("info:进入了testLog4j");
        logger.debug("debug:进入了testLog4j");
        logger.error("error:进入了testLog4j");
    }


    @Test
    public void testLimit(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        HashMap<String, Integer> map = new HashMap<>();
        map.put("startIndex",0);
        map.put("pageSize",2);
        List<User> userByLimit = mapper.getUserByLimit(map);
        for (User user : userByLimit) {
            System.out.println(user);
        }
        sqlSession.close();
    }

    @Test
    public void testRowBounds(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        RowBounds rowBounds = new RowBounds(0,2);
        //注意这里的字符串必须精确到接口中的方法名称
        List<User> users = sqlSession.selectList("mapper.UserMapper.getUserByRowBounds", null, rowBounds);
        for (User user : users) {
            System.out.println(user);
        }
        sqlSession.close();
    }
}
