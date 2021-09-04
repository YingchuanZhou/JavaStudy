package reflection;


//测试类的加载过程
public class Test04 {

    public static void main(String[] args) {
        A a = new A();
        System.out.println(a.m);

        /*
        1. 首先将类加载到内存，并且产生一个相应的Class对象
        2. 链接，链接结束后，m= 0
        3. 初始化
            <clinit>(){
                System.out.println("A类的静态代码块");
                m=300;
                m = 100;
            }
            最后m=100
         */
    }
}

class A{

    static {
        System.out.println("A类的静态代码块");
        m=300;
    }
    static int m = 100;

    public A() {
        System.out.println("A类的无参构造");
    }
}
