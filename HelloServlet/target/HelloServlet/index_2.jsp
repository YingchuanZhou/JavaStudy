<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2021/7/29
  Time: 19:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%--定制错误页面--%>
<%@page errorPage="error500.jsp" %>

<html>
<head>
    <title>Title</title>
</head>
<body>
<%--
JSP表达式，作用：用来将程序的输出，输出到客户端
<%= 变量或者表达式%>
--%>
    <%= new java.util.Date()%>

<%--JSP脚本片段--%>

    <%
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            sum+=i;
        }
        out.println("<h1>Sum="+sum+"</h1>");
    %>


<%--在jSP中嵌入html代码--%>
    <%
        for (int i = 0; i < 5; i++) {

    %>
        <h1>Hello,Word!!!<%=i%></h1>
    <%
        }
    %>

<%--JSP声明--%>
    <%!
        static {
            System.out.println("Loading Servlet");
        }
        private int global = 0;
        public void zhou(){
            System.out.println("进入了zhou方法");
        }
    %>
    <%
        int x=1/0;
    %>
</body>
</html>
