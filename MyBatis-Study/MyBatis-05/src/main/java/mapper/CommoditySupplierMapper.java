package mapper;

import pojo.CommoditySupplier;

import java.util.List;
import java.util.Map;

public interface CommoditySupplierMapper {

//    添加
    int addSupplier(CommoditySupplier commoditySupplier);

//    使用if语句
    List<CommoditySupplier> querySupplierByIf(Map<String,String> map);

//    使用choose
    List<CommoditySupplier> querySupplierByChoose(Map<String,String> map);

//    使用set
    int updateSupplier(Map<String,String> map);

//    使用foreach
    List<CommoditySupplier> querySupplierByForEach(Map map);
}
