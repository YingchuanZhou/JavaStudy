import Vue from 'vue'
import VueRouter from 'vue-router'
import Main from '../views/Main'

Vue.use(VueRouter);

export default new VueRouter({
  routes:[
    {
      path:'/login',
      name:'login',
      component: ()=> import('../views/Login')
    },{
      path: '/main/:name',
      name:'main',
      component: Main,
      props: true,
      children: [
        {
          path: '/user/profile/:id',
          component: ()=>import('../views/user/Profile')
        },
        {
          path: '/user/list',
          component: ()=>import('../views/user/List'),
          props: true
        }
      ]
    }
  ]
});
