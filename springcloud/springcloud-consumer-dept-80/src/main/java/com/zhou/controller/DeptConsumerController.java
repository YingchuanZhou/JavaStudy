package com.zhou.controller;

import com.zhou.pojo.Dept;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@RestController
public class DeptConsumerController {

//    理解：消费者不应该有service层
//    RestTemplate ...供我们直接调用就可以了，只是需要注册到spring容器中
//    参数：url,实体：Map,Class<T> responseTYpe;

    @Autowired
    private RestTemplate restTemplate;//提供多种便捷式访问远程http服务的方法，简单的restful风格的服务模板

    //Ribbon:我们这里的地址，应该是一个变量，通过服务名来访问
    //private static final String REST_URL_PREFIX = "http://localhost:8001";
    private static final String REST_URL_PREFIX = "http://SPRINGCLOUD-PROVIDER-DEPT";

    @RequestMapping("/consumer/dept/add")
    public boolean add(Dept dept){
        return restTemplate.postForObject(REST_URL_PREFIX+"/dept/add",dept,Boolean.class);
    }

    @RequestMapping("/consumer/dept/queryDept/{id}")
    public Dept queryDeptById(@PathVariable("id") int id){
        return restTemplate.getForObject(REST_URL_PREFIX+"/dept/queryDept"+id,Dept.class);
    }

    @RequestMapping("/consumer/dept/queryAll")
    public List<Dept> queryAll(){
        return restTemplate.getForObject(REST_URL_PREFIX+"/dept/queryAll",List.class);
    }
}
