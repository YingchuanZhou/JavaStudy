<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2021/8/22
  Time: 18:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>jQuery</title>
  <script>
    function a(){
      $.post({
        url:"${pageContext.request.contextPath}/a1",
        data:{"name":$("#username").val()},
        success: function (data) {
            alert(data);
        }
    })
    }

  </script>
  <script src="${pageContext.request.contextPath}/statics/js/jquery-3.6.js"></script>
  </head>
  <body>
<%--    失去焦点的时候发起一个请求(携带信息）到后台--%>
  <input type="text" id="username" onblur="a()">
  </body>
</html>
