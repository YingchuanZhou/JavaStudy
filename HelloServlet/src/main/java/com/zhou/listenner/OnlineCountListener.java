package com.zhou.listenner;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

//监听浏览器在线人数，通过Session监听，每个用户只有一个Session
public class OnlineCountListener implements HttpSessionListener {
//    创建Session监听：看你的一举一动
//    只要创建一次Session，就会触发一次事件
    @Override
    public void sessionCreated(HttpSessionEvent se) {
        ServletContext servletContext = se.getSession().getServletContext();
        Integer onlineCount = (Integer) servletContext.getAttribute("OnlineCount");
        if(onlineCount == null){
            onlineCount = new Integer(1);
        }else{
            int count = onlineCount.intValue();
            onlineCount = new Integer(count++);
        }
    servletContext.setAttribute("OnlineCount",onlineCount);

    }

//    销毁Session监听
//    一旦销毁一次Session，就会触发一次该事件
    @Override
    public void sessionDestroyed(HttpSessionEvent se) {
        ServletContext servletContext = se.getSession().getServletContext();
        Integer onlineCount = (Integer) servletContext.getAttribute("OnlineCount");
        if(onlineCount == null){
            onlineCount = new Integer(0);
        }else{
            int count = onlineCount.intValue();
            onlineCount = new Integer(count--);
        }
        servletContext.setAttribute("OnlineCount",onlineCount);
    }
}
