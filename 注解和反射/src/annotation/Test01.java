package annotation;

import java.util.ArrayList;
import java.util.List;

public class Test01 extends Object{

//    重写注解
    @Override
    public String toString(){
        return super.toString();
    }

//    不推荐使用注解
    @Deprecated
    public static void test(){
        System.out.println("Deprecated");
    }

//    镇压警告

    @SuppressWarnings("all")
    public void test02(){
        List list = new ArrayList();
    }

    public static void main(String[] args) {
        test();
    }

}
