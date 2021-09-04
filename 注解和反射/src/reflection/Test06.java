package reflection;


public class Test06 {

    public static void main(String[] args) throws ClassNotFoundException {
//        获取系统类加载器
        ClassLoader systemClassLoader =  ClassLoader.getSystemClassLoader();
        System.out.println(systemClassLoader);
//        获取系统类加载器的父加载器 -->扩展类加载器
        ClassLoader parent = systemClassLoader.getParent();
        System.out.println(parent);

//        获取扩展类加载器的父类 -->根加载器，即：引导类加载器（用C/C++写的，Java获取不到）
        ClassLoader parent1 = parent.getParent();
        System.out.println(parent1);

//        查看当前类是由哪个类加载器加载的
        ClassLoader classLoader = Class.forName("reflection.Test06").getClassLoader();
        System.out.println(classLoader);

//        测试jdk内置类的加载器
        classLoader =  Class.forName("java.lang.Object").getClassLoader();
        System.out.println(classLoader);

//        获得系统类加载器可以加载的路径
        System.out.println(System.getProperty("java.class.path"));

    }

}
