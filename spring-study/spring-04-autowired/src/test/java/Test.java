import com.zhou.pojo.People;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Test {

    @org.junit.Test
    public void test(){
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("beans.xml");

        People people = applicationContext.getBean("people", People.class);

        people.getCat().shout();
        people.getDog().shout();
    }
}
