# AJAX
* AJAX = Asynchronous JavaScript and XML（异步的 JavaScript 和 XML）。
* AJAX 是一种用于创建快速动态网页的技术。
* 通过在后台与服务器进行少量数据交换，AJAX 可以使网页实现异步更新。这意味着可以在不重新加载整个网页的情况下，对网页的某部分进行更新。
* 传统的网页（不使用 AJAX）如果需要更新内容，必需重载整个网页面
* 产品链：H5+网页+客户端+手机端（Android+IOS）+小程序
* Ajax底层就是XMLHttpRequest（xhr），XHR为向服务器发送请求和解析服务器响应提供了接口。能够异步的从服务器获取新数据。
* 使用jQuery需要先导入jQuery的js文件；
	在jsp中导入：```<script src = "${pageContext.request.contextPath}/相对路径"></script>```
* Ajax默认是get请求
* 使用jQuery查询：
	1. url：待在入页面的地址
	2. data：待发送的Key/Value参数
	3. success：载入成功时回调函数
Ajax总结：
	1. 使用jQuery需要导入jQuery
	2. 编写对应的Controller，返回消息或者字符串或者json格式数据；使用注解（@QuestBody....）
	3. 编写Ajax请求		① url Controller请求 ②data  键值对 ③success回调函数
	4. 给Ajax绑定事件，点击(click)，失去焦点(onblur)，键盘弹起(keyup)等等

```java
end:
@Controller
@RequestMapping("/ajax")
public class AjaxController{
    //第一种方式，服务器要返回一个字符串，直接使用response
    @RequestMapping("/a1")
    public void ajax(String name,HttpServletResponse response){
        if("admin".equals(name)){
            response.getWriter().print("true");
        }else{
            response.getWriter().print("false");
        }
    }
}
​
@RequestMapping("/a2")
@ResponseBody
public List<User> ajax2(){
    List<User> list =new ArrayList<>();
    User user1 =new User("豪",1,"男");
    User user2=new User("豪",1,"男");
    list.add(user1);
    list.add(user2);
    return list; //由于加了@ResponseBody注解，他会返回一个字符串
}
ajax 写法

<script type="text/javascript">
    function a1() {
        //所有参数：
        //url:待载入页面的URL地址，Json
        //data:待发送Key/value参数
        //success:载入成功时回调函数
        //data：封装了服务器返回的数据
        //status：状态
        $.ajax({
            url:"${pageContext.request.contextPath}/ajax/a1",
            data:{"name":$("txtName").val()},
            success:function (data,status) {
                console.log(data)
                console.log(status)
            }
        });
        //将文本输入的值，
        $("txtName").val();
        // //发送给服务器，
        // //接受服务器返回的数据
    }
<script>
    $(function(){
        $("#btn").click(function(){
            $.post("${pageContest.request.contextPath}/ajax/a2",function(data){
                console.log(data);
                var html="";
                for(var i=0;i<data.length;i++){
                    html+="<tr>"+
                        "<td>"+data[i].name+"</td>"+
                        "<td>"+data[i].age+"</td>"+
                        "<td>"+data[i].sex+"</td>"+
                        "</tr>"
                }
                $("#content").html(html);
            })
        })
})
</script>    
第三种#
@RequestMapping("/a3")
@ResponseBody
public String ajax3(String name,String pwd){
    String msg="";
    if(name!=null){
        if("admin".equals(name)){
            msg="ok";
        }else{
            msg="用户名有误"；
        }
    }
    if(pwd != null){
        if("123456".equals(pwd)){
            msg="ok";
        }else{
            msg="密码输入有误";
        }
            
    }
    return msg;
}
 <html>
    <head>
        <title>Title</title>
        <script>
            function a1(){
                $.post({
                    url:"${pageContext.request.contextPath}/ajax/a3",
                    data:{"name":$("#name").val()},
                    success:function(data){
                        if(data.toString()=='ok'){
                            //信息核对成功
                            $('#userInfo').css("color","green");
                        }else{
                            $("#userInfo").css("color","red");
                        }
                        $("#userInfo").html(data);
                    }
                })
            }
            function a2(){
                $.post("${pageContext.request.contextPath}/ajax/a3",{"pwd":$("pwd").val()},function(data){
                    if(data.toString()='ok'){//信息核对成功
                        $('#pwdInfo').css("color","green");                     
                    }else{
                        $('#pwdInfo').css("color","red");
                    }
                    $("#pwdInfo").html(data);
                })
            }
        </script>
    </head>
    <body>
        <p>
            用户名：
            <input type="text" id="name" onblur="a1()"/>
            <span id="userInfo"></span>
        </p>
        <p>
                密码：
            <input type="text" id="pwd" onblur="a2()"/>
            <span id="pwdInfo"></span>
            
        </p>   
        
    </body>
</html>
```