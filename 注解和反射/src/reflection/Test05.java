package reflection;

public class Test05 {
    static {
        System.out.println("Main类被加载");
    }
    public static void main(String[] args) throws ClassNotFoundException {

//        主动引用
        Son son = new Son();
//        反射也会主动引用
        Class c1 = Class.forName("reflection.Son");

//        不会初始化的情况
        System.out.println(Son.b);//通过子类调用父类的静态变量，子类不会初始化

//          通过数组定义引用不会触发初始化，相当于只是给这部分空间取了个名字
        Son[] array = new Son[5];

//        引用子类中的常量也不会触发初始化
        System.out.println(Son.M);
    }
}

class Father{
    static int b=2;
    static {
        System.out.println("父类被加载");

    }
}

class Son extends Father{
    static {
        System.out.println("子类被加载");
        m=300;
    }
    static int m = 100;
    static final int M = 1;
}
