package com.zhou.webproject.config;

import org.springframework.util.StringUtils;
import org.springframework.web.servlet.LocaleResolver;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Locale;

public class MyLocaleResolve implements LocaleResolver {
//    解析请求
    @Override
    public Locale resolveLocale(HttpServletRequest request) {
//        获取请求中的语言参数   /index.html?l=zh_CN
        String language = request.getParameter("l");
        Locale locale = Locale.getDefault();//没有就是用默认的
//        如果请求携带了国际化参数
        if(StringUtils.isEmpty(language)){
//            zh_CN
            String[] split = language.split("_");
            locale = new Locale(split[0],split[1]);
        }
        return locale;
    }

    @Override
    public void setLocale(HttpServletRequest request, HttpServletResponse response, Locale locale) {

    }
}
