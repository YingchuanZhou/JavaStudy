package mapper;

import org.apache.ibatis.annotations.Param;
import pojo.Student;
import pojo.Teacher;

import java.util.List;

public interface TeacherMapper {

    //查询一个指定老师对应得多个学生
    Teacher getTeacher(@Param("tid") int id);

    Teacher getTeacher2(@Param("tid") int id);
}
