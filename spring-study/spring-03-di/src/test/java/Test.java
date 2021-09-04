import com.zhou.pojo.Student;
import com.zhou.pojo.User;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Test {
    public static void main(String[] args) {

        ApplicationContext applicationContext  = new ClassPathXmlApplicationContext("applicationContext.xml");

        Student student = (Student) applicationContext.getBean("student");

        System.out.println(student);

        /*
        Student{
            name='周迎川',
            address=Address{
            address='重庆'
             },
             books=[Java, Python, C++, Spring],
            hobbies=[写代码, 看电影, 听歌, 学习],
             card={
                身份证=500235199911152222,
                银行卡=6215281055252724
            },
            games=[LOL, CF, QQ飞车],
            wife='null',
            info={
                姓名=周迎川,
                学号=631907060434,
                性别=男
            }
         }

         */
    }

    @org.junit.Test
    public void test(){
        ApplicationContext context = new ClassPathXmlApplicationContext("userbeans.xml");
        User user = context.getBean("user", User.class);
        System.out.println(user);
    }
    @org.junit.Test
    public void test2(){
        ApplicationContext context = new ClassPathXmlApplicationContext("userbeans.xml");
        User user = context.getBean("user2", User.class);
        System.out.println(user);
    }
}
