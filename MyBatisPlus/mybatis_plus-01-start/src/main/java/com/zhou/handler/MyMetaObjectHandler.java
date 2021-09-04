package com.zhou.handler;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import lombok.extern.slf4j.Slf4j;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.stereotype.Component;

import java.util.Date;

//打印日志输出
@Slf4j
//交给Spring管理，加入IOC容器中
@Component
public class MyMetaObjectHandler implements MetaObjectHandler {

//    插入时填充
    @Override
    public void insertFill(MetaObject metaObject) {

        log.info("start insert fill ....");
//        MetaObjectHandler setFieldValByName(String fieldName, Object fieldVal, MetaObject metaObject)
        this.setFieldValByName("createTime",new Date(),metaObject);
        this.setFieldValByName("updateTime",new Date(),metaObject);
    }

//    更新时填充
    @Override
    public void updateFill(MetaObject metaObject) {

        log.info("start update fill ....");
        this.setFieldValByName("updateTime",new Date(),metaObject);
    }
}
