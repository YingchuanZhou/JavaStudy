// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import VueRouter from "vue-router";

// import router from './router/index'
import router from './router'   //会自动扫描里面的路由配置

Vue.config.productionTip = false

//显示声明使用VueRouter
Vue.use(VueRouter);

/* eslint-disable no-new */
new Vue({
  el: '#app',
  //配置路由
  router,
  components: { App },
  template: '<App/>'
})
