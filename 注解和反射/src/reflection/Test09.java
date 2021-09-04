package reflection;

import java.lang.annotation.*;
import java.lang.reflect.Field;

//练习反射操作注解
public class Test09 {

    public static void main(String[] args) throws ClassNotFoundException, NoSuchFieldException {
        Class c = Class.forName("reflection.Student2");
//        获得注解
        Annotation[] annotations = c.getAnnotations();
        for (Annotation annotation : annotations) {
            System.out.println(annotation);
        }

//        获得注解的value值
        TableZYC tableZYC = (TableZYC) c.getAnnotation(TableZYC.class);
        String value = tableZYC.value();
        System.out.println(value);

//        获得指定属性的注解
        Field name = c.getDeclaredField("name");
        FieldZYC annotation = name.getAnnotation(FieldZYC.class);
        System.out.println(annotation.columnName());
        System.out.println(annotation.type());
        System.out.println(annotation.length());

    }
}
@TableZYC("db_student")
class Student2{
    @FieldZYC(columnName = "db_id",type = "int",length = 10)
    private int id;
    @FieldZYC(columnName = "db_age",type = "int",length = 10)
    private int age;
    @FieldZYC(columnName = "db_name",type = "varchar",length = 10)
    private String name;

    public Student2() {
    }

    public Student2(int id, int age, String name) {
        this.id = id;
        this.age = age;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Student2{" +
                "id=" + id +
                ", age=" + age +
                ", name='" + name + '\'' +
                '}';
    }
}

//类名的注解
@Target(ElementType.TYPE)
@Retention(RetentionPolicy.RUNTIME)
@interface TableZYC{
    String value();
}

//属性的注解
@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
@interface FieldZYC{
    String columnName();
    String type();
    int length();
}


