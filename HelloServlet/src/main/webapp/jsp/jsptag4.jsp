<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%--    定义一个变量score，值为85--%>
    <c:set var="score" value="85"></c:set>
    <c:choose>
        <c:when test="${score}>=90">
            优秀
        </c:when>
        <c:when test="${score}>=80">
            良好
        </c:when>
        <c:when test="${score}>=70">
            一般
        </c:when>
    </c:choose>
</body>
</html>
