package createthread;

//多个线程同时操作同一个对象
//以买票为例

//发现问题：多个线程操作同一个资源的情况下，线程不安全，数据紊乱
public class TestThead3 implements Runnable{

//    票数
    private int ticketNums = 10;

    public void run() {
        while (true){
            if (ticketNums <= 0){
                break;
            }

//            模拟延时
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName()+"--->拿到了第"+ticketNums--+"张票");
        }
    }

    public static void main(String[] args) {
        TestThead3 tick = new TestThead3();

        new Thread(tick,"ZZZ").start();
        new Thread(tick,"WWW").start();
        new Thread(tick,"HHH").start();
    }
}
