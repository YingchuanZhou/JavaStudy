<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2021/7/31
  Time: 9:10
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>内置对象</title>
</head>
<body>
<%--内置对象--%>

    <%
        pageContext.setAttribute("name1","周迎川1");//保存数据只在一个页面有效，页面跳转之后无效
        request.setAttribute("name2","周迎川2");//保存的数据只在一次请求中有效，请求转发会携带这个数据
        session.setAttribute("name3","周迎川3");//保存的数据只在一次会话中有效，从打开浏览器到关闭浏览器
        application.setAttribute("name4","周迎川4");//保存的数据只在服务器中有效，从打开服务器到关闭服务器
    %>

<%--脚本片段中的代码一定要是Java代码，会被原封不动的保存到.JSP.java中
所以这里的代码一定是与Java语相同的包括注释--%>

    <%
        String name1 = (String) pageContext.getAttribute("name1");
        String name2 = (String) pageContext.getAttribute("name2");
        String name3 = (String) pageContext.getAttribute("name3");
        String name4 = (String) pageContext.getAttribute("name4");
        String name5 = (String) pageContext.getAttribute("name5");//不存在
//        从pageContext中来，通过寻址方式来
//        寻找方式：从底层到高层（作用域）：page -->request -->session --> application
//        JVM中的双亲委派机制
//        String name1 = (String) pageContext.findAttribute("name1");
//        String name2 = (String) pageContext.findAttribute("name1");
//        String name3 = (String) pageContext.findAttribute("name1");
//        String name4 = (String) pageContext.findAttribute("name1");
//        String name5 = (String) pageContext.findAttribute("name1");
    %>

<%--输出获取到的值--%>
    <h1>得到的值：</h1>
<%--使用EL表达式输出 ${}--%>
    <h3>${name1}</h3>
    <h3>${name2}</h3>
    <h3>${name3}</h3>
    <h3>${name4}</h3>
    <h3>${name5}</h3>
</body>
</html>
