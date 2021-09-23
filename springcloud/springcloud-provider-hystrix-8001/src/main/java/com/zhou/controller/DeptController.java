package com.zhou.controller;

import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import com.zhou.pojo.Dept;
import com.zhou.service.DeptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class DeptController {

    @Autowired
    private DeptService deptService;

    /**
     * 根据id查询部门信息
     * 如果根据id查询出现异常,则走hystrixGet这段备选代码
     *
     * @param id
     * @return
     */
    @HystrixCommand(fallbackMethod = "hystrixGet")
    @RequestMapping("/dept/get/{id}")//根据id查询
    public Dept get(@PathVariable("id") int id) {
        Dept dept = deptService.queryDept(id);
        if (dept == null) {
            throw new RuntimeException("这个id=>" + id + ",不存在该用户，或信息无法找到~");
        }
        return dept;
    }

    /**
     * 根据id查询备选方案(熔断)
     *
     * @param id
     * @return
     */
    public Dept hystrixGet(@PathVariable("id") int id) {
        return new Dept().setDeptno(id)
                .setDname("这个id=>" + id + ",没有对应的信息,null---@Hystrix~")
                .setDb_source("在MySQL中没有这个数据库");
    }
}
