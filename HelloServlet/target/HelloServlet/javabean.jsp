<%@ page import="com.zhou.pojo.Person" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>

<%--    <%--%>
<%--        Person person = new Person();--%>
<%--        person.setName("周迎川");--%>
<%--        person.setAge(21);--%>
<%--    %>--%>
    <jsp:useBean id="person" class="com.zhou.pojo.Person" scope="page">
        <jsp:setProperty name="person" property="name" value="周迎川"></jsp:setProperty>
        <jsp:setProperty name="person" property="age" value="21"></jsp:setProperty>
    </jsp:useBean>

<%--    <%=person.getName()%>--%>
<%--    <%=person.getAge()%>--%>
姓名：<jsp:getProperty name="person" property="name"/>
年龄：<jsp:getProperty name="person" property="age"/>

</body>
</html>
