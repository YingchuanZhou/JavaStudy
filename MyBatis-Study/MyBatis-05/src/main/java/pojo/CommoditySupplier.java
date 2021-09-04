package pojo;

import lombok.Data;

@Data
public class CommoditySupplier {

//    这里的属性名与数据库的字段不一样  supplier_no，
//    这里采用了驼峰命名，后面需要处理才能与数据库字段对应，需要在核心配置文件setting中设置
    private String supplierNo;
    private String supplierName;
    private String linkman;
    private String telNumber;
    private String supplierIntroduce;

    public CommoditySupplier(String supplierNo, String supplierName, String linkman, String telNumber, String supplierIntroduce) {
        this.supplierNo = supplierNo;
        this.supplierName = supplierName;
        this.linkman = linkman;
        this.telNumber = telNumber;
        this.supplierIntroduce = supplierIntroduce;
    }
}
