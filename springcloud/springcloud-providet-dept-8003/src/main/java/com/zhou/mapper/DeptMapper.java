package com.zhou.mapper;

import com.zhou.pojo.Dept;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface DeptMapper {

    public boolean addDept(Dept dept);

    public Dept queryDept(int id);

    public List<Dept> queryAll();
}
