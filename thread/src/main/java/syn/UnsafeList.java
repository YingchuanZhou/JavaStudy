package syn;

import java.util.ArrayList;

public class UnsafeList {
    public static void main(String[] args) {
        ArrayList<String> list=new ArrayList<String>();
        for (int i = 0; i <1000 ; i++) {
            new Thread( () ->{
                synchronized (list){
                    list.add(Thread.currentThread().getName());
                }
            }).start();
            try {
                Thread.sleep(30);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(list.size());
    }
}