package createthread;

//创建线程得方式一：继承Thead类，重写run方法，调用start开启线程
public class TestThread extends Thread{
    @Override
    public void run() {
//        Run方法线程体
        for (int i = 0; i < 20; i++) {
            System.out.println("我在看代码"+i);
        }
    }

    public static void main(String[] args) {
//        main线程，主线程

//        创建一个线程对象
        TestThread testThread = new TestThread();

//        调用start方法执行线程，但是线程不一定立即执行，由CPU调度安排
        testThread.start();

        for (int i = 0; i < 1000; i++) {
            System.out.println("我在学习多线程"+i);
        }
    }
}
