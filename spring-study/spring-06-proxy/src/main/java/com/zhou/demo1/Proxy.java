package com.zhou.demo1;

public class Proxy implements Rent{

    private Host host;

    public Proxy() {
    }

    public Proxy(Host host) {
        this.host = host;
    }

    public Host getHost() {
        return host;
    }

    public void setHost(Host host) {
        this.host = host;
    }


    @Override
    public void rent() {
        host.rent();
        seeHouse();
        fare();
    }

//    中介还能进行一些附属操作
//   比如看房，收中介费
    public void seeHouse(){
        System.out.println("中介看房");
    }

    public void fare(){
        System.out.println("中介收中介费");
    }
}
