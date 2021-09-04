package mapper;

import org.apache.ibatis.session.SqlSession;
import org.junit.Test;
import pojo.CommoditySupplier;
import utils.IdUtil;
import utils.MyBatisUtil;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class SupplierTest {

    @Test
    public void testAdd(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        CommoditySupplierMapper mapper = sqlSession.getMapper(CommoditySupplierMapper.class);
        CommoditySupplier commoditySupplier = new CommoditySupplier(IdUtil.getId(),"百度","李彦宏","1111111888","你不知道的这里都有");
        int i = mapper.addSupplier(commoditySupplier);
        System.out.println(i);
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void querySupplierByIf(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        CommoditySupplierMapper mapper = sqlSession.getMapper(CommoditySupplierMapper.class);
        HashMap<String, String> map = new HashMap<>();
        map.put("supplierNo","1111");
        map.put("supplierName","阿里巴巴");
        List<CommoditySupplier> commoditySuppliers = mapper.querySupplierByIf(map);
        for (CommoditySupplier commoditySupplier : commoditySuppliers) {
            System.out.println(commoditySupplier);
        }
        sqlSession.close();
    }


    @Test
    public void querySupplierByChoose(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        CommoditySupplierMapper mapper = sqlSession.getMapper(CommoditySupplierMapper.class);
        HashMap<String, String> map = new HashMap<>();
        map.put("supplierNo","2222");
//        map.put("supplierName","字节跳动");
//        map.put("linkman","王一鸣");
        List<CommoditySupplier> commoditySuppliers = mapper.querySupplierByChoose(map);
        for (CommoditySupplier commoditySupplier : commoditySuppliers) {
            System.out.println(commoditySupplier);
        }
        sqlSession.close();
    }

    @Test
    public void querySupplierBySet(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        CommoditySupplierMapper mapper = sqlSession.getMapper(CommoditySupplierMapper.class);
        HashMap<String, String> map = new HashMap<>();
        map.put("supplierNo","1111");
        map.put("supplierName","阿里巴巴");
        map.put("linkman","张勇");
        int i = mapper.updateSupplier(map);
        if (i>0){
            sqlSession.commit();
        }
        sqlSession.close();
    }


    @Test
    public void querySupplierByForEach(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        CommoditySupplierMapper mapper = sqlSession.getMapper(CommoditySupplierMapper.class);
        HashMap<String, Object> map = new HashMap<>();
        ArrayList<String> list = new ArrayList<>();
        list.add("1111");
        list.add("2222");
        map.put("ids",list);
        List<CommoditySupplier> commoditySuppliers = mapper.querySupplierByForEach(map);
        for (CommoditySupplier commoditySupplier : commoditySuppliers) {
            System.out.println(commoditySupplier);
        }
        sqlSession.close();
    }
}
