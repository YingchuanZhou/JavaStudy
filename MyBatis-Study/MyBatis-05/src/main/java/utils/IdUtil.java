package utils;

import org.junit.Test;

import java.util.UUID;

public class IdUtil {

    public static String getId(){
//        数据库主键自增有缺陷，id只能增加，不能生成前面删除的id
//        使用UUID类，实现随机产生个id
        return UUID.randomUUID().toString().replace("-","");
    }

    @Test
    public void test(){
        System.out.println(IdUtil.getId());
    }
}
