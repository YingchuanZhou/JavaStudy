package com.zhou.webproject.dao;

import com.zhou.webproject.pojo.Department;
import com.zhou.webproject.pojo.Employee;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

@Repository
public class EmployeeDao {
    private static Map<Integer, Employee> employees;

    @Autowired
    private DepartmentDao departmentDao;


    static {
        employees = new HashMap<>();

        employees.put(1001, new Employee(1001, "ZZ", "766623393@qq.com", 1, new Department(101, "教学部"), new Date()));
        employees.put(1002, new Employee(1002, "ZJ", "766623393@qq.com", 0, new Department(102, "市场部"), new Date()));
        employees.put(1003, new Employee(1003, "ZF", "766623393@qq.com", 1, new Department(103, "教研部"), new Date()));
        employees.put(1004, new Employee(1004, "ZD", "766623393@qq.com", 0, new Department(104, "运营部"), new Date()));
        employees.put(1005, new Employee(1005, "ZC", "766623393@qq.com", 1, new Department(105, "后勤部"), new Date()));

    }

    //    主键自增
    private static Integer initId = 1006;

    //增加员工
    public void add(Employee employee) {
        if (employee.getId() == null) {
            employee.setId(initId++);
        }

        employee.setDepartment(departmentDao.getDepartmentById(employee.getDepartment().getId()));

        employees.put(employee.getId(), employee);
    }

    //    查询全部员工
    public Collection<Employee> getAll() {
        return employees.values();
    }

//    通过id查询员工

    public Employee getEmployeeById(Integer id){
        return employees.get(id);
    }

//    删除员工
    public void delete(Integer id){
        employees.remove(id);
    }
}