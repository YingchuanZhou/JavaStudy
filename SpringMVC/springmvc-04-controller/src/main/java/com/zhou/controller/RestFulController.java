package com.zhou.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class RestFulController {

//    原来：    http://localhost:8080/add?a=1&b=1
//    RestFul: http://localhost:8080/add/1/1

    @RequestMapping("/add")
    public String test(int a, int b, Model model){
        int res = a+b;
        model.addAttribute("msg","结果为"+res);
        return "test1";
    }

//    RestFul
//    @RequestMapping(value="/add/{a]/{b}",method = RequestMethod.GET)
//    @RequestMapping(path="/add/{a]/{b}",method = RequestMethod.GET)
    @GetMapping("/add/{a]/{b}")
    public String test2(@PathVariable int a, @PathVariable int b, Model model){
        int res = a+b;
        model.addAttribute("msg","结果为"+res);
        return "test1";
    }

}
