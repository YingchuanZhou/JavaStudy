
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <h1>1</h1>
<%--    <jsp:include page=""></jsp:include>--%>
    <%--引入网页头部，会将页面合起来--%>
    <%@include file="../common/header.jsp"%>
    <h1>网页主体</h1>


    <%--JSP标签，只是拼接页面，本质还是原来的个数--%>
    <jsp:include page="/common/header.jsp"></jsp:include>
<%--
请求转发，
原来的：http://localhost:8080/jsptag.jsp
加参数后：http://localhost:8080/jsptag.jsp?name=zhou&age=21
--%>
    <jsp:forward page="/jsp/jsptag2.jsp">
        <jsp:param name="name" value="zhou"/>
        <jsp:param name="age" value="21"/>
    </jsp:forward>
</body>
</html>
