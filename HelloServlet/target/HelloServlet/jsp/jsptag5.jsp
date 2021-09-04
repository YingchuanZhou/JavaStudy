<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="java.util.ArrayList" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%--forEach--%>
    <%
        ArrayList<String> list = new ArrayList<String>();
        list.add("周迎川");
        list.add("吕华川");
        list.add("方圆");
        request.setAttribute("list",list);
    %>
    <c:forEach var="people" items="${list}">
        <c:out value="${people}"></c:out>
    </c:forEach>
<c:forEach var="people" items="${list}" begin="" end="" step="">
    <c:out value="${people}"></c:out>
</c:forEach>
</body>
</html>
