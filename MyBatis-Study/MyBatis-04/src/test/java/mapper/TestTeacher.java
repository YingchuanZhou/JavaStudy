package mapper;

import org.apache.ibatis.session.SqlSession;
import org.junit.Test;
import pojo.Teacher;
import utils.MyBatisUtil;


public class TestTeacher {

    @Test
    public void test(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        TeacherMapper mapper = sqlSession.getMapper(TeacherMapper.class);
        Teacher teacher = mapper.getTeacher(1);
        System.out.println(teacher);
        /*
        Teacher(
        id=1, name=周迎川,
         students=
         [Student(name=陈涵, id=631907060501, tid=1, teacher=null),
         Student(name=王小红, id=631907060434, tid=1, teacher=null),
         Student(name=曾静, id=189510205, tid=1, teacher=null),
         Student(name=曲洪洋, id=631907060520, tid=1, teacher=null),
          Student(name=董不懂, id=631907060305, tid=1, teacher=null)])
         */
        sqlSession.close();
    }


    @Test
    public void test2(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        TeacherMapper mapper = sqlSession.getMapper(TeacherMapper.class);
        Teacher teacher = mapper.getTeacher(1);
        System.out.println(teacher);
        /*
        Teacher(
        id=1, name=周迎川,
         students=
         [Student(name=陈涵, id=631907060501, tid=1, teacher=null),
         Student(name=王小红, id=631907060434, tid=1, teacher=null),
         Student(name=曾静, id=189510205, tid=1, teacher=null),
         Student(name=曲洪洋, id=631907060520, tid=1, teacher=null),
          Student(name=董不懂, id=631907060305, tid=1, teacher=null)])
         */
        sqlSession.close();
    }
}
