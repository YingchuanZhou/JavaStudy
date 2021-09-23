package com.zhou.service;

import com.zhou.mapper.DeptMapper;
import com.zhou.pojo.Dept;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DeptServiceImpl implements DeptService{

    @Autowired
    private DeptMapper deptMapper;

    @Override
    public boolean addDept(Dept dept) {
        return deptMapper.addDept(dept);
    }

    @Override
    public Dept queryDept(int id) {
        return deptMapper.queryDept(id);
    }

    @Override
    public List<Dept> queryAll() {
        return deptMapper.queryAll() ;
    }
}
