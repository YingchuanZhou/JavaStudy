package annotation;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

public class Test02 {
    @MyAnnotation(name = "周迎川")
    public void test(){

    }

    @MyAnnotation3("111")
    public void test02(){

    }

}
//自定义注解
@Target({ElementType.TYPE,ElementType.METHOD})
@Retention(RetentionPolicy.RUNTIME)
@interface MyAnnotation{

//    注解参数：注解参数类型+参数名称 ()
    String name() default "";
    int age() default 0;
    int id() default -1;//如果默认值为-1，代表不存在，和indexof相似，找不到返回-1
    String[] schools() default {"重庆交通大写","重庆大学"};
}

//自定义注解
@Target({ElementType.TYPE,ElementType.METHOD})
@Retention(RetentionPolicy.RUNTIME)
@interface MyAnnotation3{
    String value();
}