package com.zhou.config;

import com.zhou.pojo.User;
import com.zhou.service.UserService;
import org.apache.shiro.SecurityUtils;
import org.apache.shiro.authc.*;
import org.apache.shiro.authz.AuthorizationInfo;
import org.apache.shiro.authz.SimpleAuthorizationInfo;
import org.apache.shiro.realm.AuthorizingRealm;
import org.apache.shiro.session.Session;
import org.apache.shiro.subject.PrincipalCollection;
import org.apache.shiro.subject.Subject;
import org.springframework.beans.factory.annotation.Autowired;

//自定义的UserRealm类，   extends AuthorizingRealm
public class UserRealm extends AuthorizingRealm {

    @Autowired
    private UserService userService;

//    授权
    @Override
    protected AuthorizationInfo doGetAuthorizationInfo(PrincipalCollection principalCollection) {
        System.out.println("执行了=》授权doGetAuthorizationInfo");

//        创建授权对象    SimpleAuthorizationInfo
        SimpleAuthorizationInfo info = new SimpleAuthorizationInfo();
//        授予权限
        info.addStringPermission("user:add");

//        拿到当前用户
        Subject subject = SecurityUtils.getSubject();
//        获取认证中传递过来的用户信息
        User currentUser = (User) subject.getPrincipal();//拿到user对象

//        给当前用户授权
        info.addStringPermission(currentUser.getPerms());

        return info;
    }

//    认证
    @Override
    protected AuthenticationInfo doGetAuthenticationInfo(AuthenticationToken authenticationToken) throws AuthenticationException {
        System.out.println("执行了=》认证doGetAuthorizationInfo");
//        用户名密码，从数据库取出，这里完成认证

//        String username = "zyc";
//        String password = "123456";

//        这个令牌是我们在登录控制器中封装的token，在整个类中都可以访问
        UsernamePasswordToken userToken = (UsernamePasswordToken) authenticationToken;

        User user = userService.queryUserByName(userToken.getUsername());
        if(user==null){
            return null; //没有该用户，抛出异常，UnknownAccountException
        }
//        if (!userToken.getUsername().equals(username)){
//            return null;    // 如果用户名不对，返回null，抛出异常，UnknownAccountException
//        }

//        将当前用户保存到session中
        Subject subject = SecurityUtils.getSubject();
        Session session = subject.getSession();
        session.setAttribute("loginUser",user);

//        密码认证Shiro帮我们做，加密了
//        第一个参数的值可以在授权中得到，如果要在授权中得到user的信息，必须要传递
        return new SimpleAuthenticationInfo(user,user.getPassword(),"");
    }
}
