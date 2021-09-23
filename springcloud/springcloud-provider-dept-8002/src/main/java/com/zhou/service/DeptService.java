package com.zhou.service;

import com.zhou.pojo.Dept;

import java.util.List;

public interface DeptService {
    public boolean addDept(Dept dept);

    public Dept queryDept(int id);

    public List<Dept> queryAll();
}
