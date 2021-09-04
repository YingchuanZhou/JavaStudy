package com.zhou.servlet;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URLEncoder;

public class FileServlet extends HelloServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        1. 要获取下载文件的路径
        String realPath = this.getServletContext().getRealPath("/2.png");
        System.out.println("下载文件路径："+realPath);
//        2. 要下载文件的名字
        String fileName = realPath.substring(realPath.indexOf("\\") + 1);
//        3. 让浏览器能够支持(content-disposition)我们下载需要的文件 ,有中文路径则需要：URLEncoder.encode(fileName,"UTF-8")
//        resp.setHeader("content-disposition", "attachment;filename="+fileName);
        resp.setHeader("content-disposition", "attachment;filename="+ URLEncoder.encode(fileName,"UTF-8"));
//        4. 获取文件下载的输入流
        FileInputStream fileInputStream = new FileInputStream(realPath);
//        5. 创建缓冲区
        int len = 0;
        byte[] buffer = new byte[1024];
//        6. 获取OutputStream对象
        ServletOutputStream outputStream = resp.getOutputStream();
//        7. 将FileOutputStram流写入到buffer缓冲区
//        8. 使用OutputStream对象将缓冲区的数据输出到客户端
        while ((len = fileInputStream.read())>0){
            outputStream.write(buffer,0,len);
        }

        fileInputStream.close();
        outputStream.close();

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
