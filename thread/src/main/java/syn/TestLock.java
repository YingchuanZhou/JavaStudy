package syn;

import java.util.concurrent.locks.ReentrantLock;

public class TestLock {
    public static void main(String[] args) {
        Ticket ticket = new Ticket();
        new Thread(ticket).start();
        new Thread(ticket).start();
        new Thread(ticket).start();
    }

}
class Ticket extends Thread{
    private int ticketNums=10;
    //定义lock锁
    private final ReentrantLock lock=new ReentrantLock();

    @Override
    public void run() {
        while (true){
            try {
                lock.lock();//加锁
                if (ticketNums > 0) {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println(ticketNums--);
                } else {
                    break;
                }
            }finally {
                lock.unlock();//减锁
            }
        }
    }
}
