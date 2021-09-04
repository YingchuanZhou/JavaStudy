import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.User;

public class Test {

    public static void main(String[] args) {
//        Spring容器，里面有很多对象，但是每个对象的实例只保存一个
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        User user = (User) applicationContext.getBean("user");
        User user2 = (User) applicationContext.getBean("user");
        System.out.println(user.equals(user2));
        user.show();
    }
}
