package createthread;

//创建线程的方式二：实现Runnable接口，重写run方法，线程需要使用线程对象开启，并且丢入Runnable接口的实现类对象
public class TestThread2 implements Runnable{

    public void run() {
//        Run方法线程体
        for (int i = 0; i < 20; i++) {
            System.out.println("我在看代码"+i);
        }
    }

    public static void main(String[] args) {
//        创建Runnable接口实现类的对象

        TestThread2 testThread2 = new TestThread2();

//        创建线程对象，通过线程对象来开启线程，通过代理的方式
        Thread thread = new Thread(testThread2);
        thread.start();

//        简写
//        new Thread(testThread2).start();
        for (int i = 0; i < 1000; i++) {
            System.out.println("我在学习多线程"+i);
        }
    }
}
