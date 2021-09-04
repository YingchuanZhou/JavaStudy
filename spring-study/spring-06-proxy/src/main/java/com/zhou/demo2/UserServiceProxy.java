package com.zhou.demo2;

public class UserServiceProxy implements UserService{

    UserServiceImpl userServiceImpl;

    public void setUserServiceImpl(UserServiceImpl userServiceImpl) {
        this.userServiceImpl = userServiceImpl;
    }

    @Override
    public void add() {
        log("add");
        userServiceImpl.add();
    }

    @Override
    public void delete() {
        log("delete");
        userServiceImpl.delete();
    }

    @Override
    public void update() {
        log("update");
        userServiceImpl.update();
    }

    @Override
    public void query() {
        log("query");
        userServiceImpl.query();
    }

//    新增加一个日志功能，尽量不要去改变已经有的代码
    public void log(String msg){
        System.out.println("[Debug] 使用了"+msg+"方法");
    }
}
