package com.zhou;

import com.zhou.pojo.Dog;
import com.zhou.pojo.Person;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class ConfigApplicationTests {

    @Autowired
    private Dog dog;

    @Autowired
    private Person person;

    @Test
    void contextLoads() {
        System.out.println(dog);
    }

    @Test
    void contextLoads2() {
        System.out.println(person);
    }

}
