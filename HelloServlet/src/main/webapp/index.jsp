<html>
<body>
<h2>Hello World!</h2>
<%--action中写的是提交路径，需要寻找到项目的路径--%>
<%--${pageContext.request.contextPath}代表当前的项目路径--%>
<form action="${pageContext.request.contextPath}/login" method="get">
    账号：<input type="text" name="username"/>
    密码：<input type="password" name="password"/>
    <input type="submit"/>
</form>
</body>
</html>
