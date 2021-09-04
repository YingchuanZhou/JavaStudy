<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%--if测试--%>
    <h1>if测试</h1>
    <hr>
    <form action="jsptag3.jsp" method="get">
<%--
    EL表达式获取表单数据
    ${param.参数名}
--%>
        <input type="text" name="username" value="${param.username}">
        <input type="submit" value="提交">
    </form>

<%--判断如果是管理员就登录成功--%>
    <%
        if (request.getParameter("username") == "admin"){
            out.print("登录成功");
        }
    %>
    <c:if test="${param.username == 'admin'}" var="isAdmin">
        <c:out value="管理员欢迎你"></c:out>
    </c:if>
    <c:out value="${isAdmin}"></c:out>
</body>
</html>
