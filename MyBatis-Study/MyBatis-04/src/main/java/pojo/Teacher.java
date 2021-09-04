package pojo;

import lombok.Data;

import java.util.List;

@Data
public class Teacher {
    private int id;
    private String name;

//    定义学生属性
    private List<Student> students;
}
