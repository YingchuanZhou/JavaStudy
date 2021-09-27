package com.zhou.utils;

import com.zhou.pojo.Content;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;

public class HtmlParseUtil {

    public static void main(String[] args) throws Exception {
        new HtmlParseUtil().parseJD("java").forEach(System.out::println);
    }

    public List<Content> parseJD(String keywords) throws Exception {
        //    获取请求    https://search.jd.com/Search?keyword=java&enc=utf-8&wq=java&pvid=e337722f37f4450aa37e296f09fc98e3
//    前提，需要联网， ajax数据不能获取，需要模拟浏览器才能获取ajax数据
        String url = "https://search.jd.com/Search?keyword="+keywords;
//    解析网页 (Jsoup 返回的Document对象就是浏览器的Document对象）
        Document document = Jsoup.parse(new URL(url), 30000);
//      在JS中能使用的方法，这里都能使用
        Element element = document.getElementById("J_goodsList");
//        获取所有的li标签
        Elements lis = element.getElementsByTag("li");
        List<Content> contents = new ArrayList<>();
//        获取元素中的内容
        for (Element li : lis) {
//            很多公司开发，出于性能考虑，通常会进行懒加载图片
            String img = li.getElementsByTag("img").eq(0).attr("source-data-lazy");
            String price = li.getElementsByClass("p-price").eq(0).text();
            String title = li.getElementsByClass("p-name").eq(0).text();
            Content content = new Content(img,title,price);
            contents.add(content);
        }

        return contents;
    }
}
