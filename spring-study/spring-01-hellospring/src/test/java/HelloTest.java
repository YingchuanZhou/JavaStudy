import com.zhou.pojo.Hello;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class HelloTest {

    public static void main(String[] args) {

//        获取Spring的上下文对象
        ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");

//        我们的对象都在Spring中管理了，我们要使用，
//        直接去里面取出来就行,参数为Spring配置文件中bean的id
        Hello hello = (Hello) context.getBean("hello");
        System.out.println(hello.toString());
    }
}