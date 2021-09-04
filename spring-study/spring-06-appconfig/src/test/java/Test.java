import com.zhou.config.MyConfig;
import com.zhou.pojo.User;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Test {
    public static void main(String[] args) {
//        如果完全使用了配置类去做，我们只能通过AnnotationConfig 上下文获取容器，通过配置类的class对象加载
        ApplicationContext context = new AnnotationConfigApplicationContext(MyConfig.class);
        User getUser = (User) context.getBean("getUser");

        System.out.println(getUser.getName());
    }
}
