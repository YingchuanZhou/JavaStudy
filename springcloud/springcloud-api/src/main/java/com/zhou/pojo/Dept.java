package com.zhou.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.experimental.Accessors;

import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Accessors(chain = true)  //链式写法
public class Dept implements Serializable {
    //Dept 实体类，必须序列化，不然在传输的时候会报错  orm  类的关系映射

    private int deptno; //主键
    private String dname;   //数据库名称

//    这个数据库存在哪个数据库中，微服务框架中，一个微服务可能对应一个数据库，
//    同一个信息可能存在不同的数据库中，
    private String db_source;

    public Dept(String dname) {
        this.dname = dname;
    }

    /*
     * 链式写法：
     *Dept dept = new Dept();
     *dept.setDeptNo(11).setDname(‘sss').setDb_source('001')
     */
}
