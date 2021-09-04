package pojo;

import lombok.Data;

@Data
public class Student {
    private String name;
    private String id;
    private int tid;
    private Teacher teacher;
}
