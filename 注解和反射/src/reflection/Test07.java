package reflection;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

//获取类的信息
public class Test07 {

    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException {
        Class c = Class.forName("reflection.User");
//        获取类的名字
        System.out.println(c.getName());//包名加类名
        System.out.println(c.getSimpleName());//只有类名

//        获取类的属性
        System.out.println("==================");
        Field[] fields = c.getFields();//找到到public属性
        for (Field field : fields) {
            System.out.println(field);
        }

        Field[] declaredFields = c.getDeclaredFields();//找到全部的属性
        for (Field declaredField : declaredFields) {
            System.out.println(declaredField);
        }

//        获取类的方法
        System.out.println("=======================");
        Method[] methods = c.getMethods();//获取本类和父类的全部public方法
        for (Method method : methods) {
            System.out.println(method);
        }

        Method[] declaredMethods = c.getDeclaredMethods();//获取本类的所有方法
        for (Method declaredMethod : declaredMethods) {
            System.out.println(declaredMethod);
        }

//      获得指定方法,必须指定参数，因为有方法重载
        Method setName = c.getMethod("setName", String.class);
        System.out.println(setName);
//        获取构造器
        Constructor[] constructors = c.getConstructors();


    }
}

