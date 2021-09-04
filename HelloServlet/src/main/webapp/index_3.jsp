<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2021/7/29
  Time: 20:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>


<%--引入网页头部，会将页面合起来--%>
    <%@include file="common/header.jsp"%>
    <h1>网页主体</h1>


<%--JSP标签，只是拼接页面，本质还是原来的个数--%>
    <jsp:include page="/common/header.jsp"></jsp:include>
</body>
</html>
