package reflection;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

//通过反射动态的创建对象
public class Test08 {
    public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException, NoSuchFieldException {
        //获得class对象
        Class c = Class.forName("reflection.User");
        User user =(User) c.newInstance();//调用了无参构造器
        System.out.println(user);

//        通过构造器创建对象
        Constructor constructor = c.getDeclaredConstructor(String.class, int.class, int.class);//调用了有参构造
        User user2 = (User)constructor.newInstance("周迎川",001,21);
        System.out.println(user2);

//        通过反射调用普通方法
        Method setName = c.getDeclaredMethod("setName", String.class);
//        invoke：激活，执行该方法，传递的参数值（对象，方法的值）
        setName.invoke(user,"周迎川");
        System.out.println(user.getName());
//        通过反射设置属性
        Field age = c.getDeclaredField("age");
//        不能直接操作类的私有属性，我们需要关闭程序的安全检测，属性或者方法的setAccessible(true)，将其设置为可用
        age.setAccessible(true);
        age.set(user,88);
        System.out.println(user.getAge());

    }
}
