<template>
  <div>
    <h1>个人信息</h1>
    {{$route.params.id}}
  </div>
</template>

<script>
  export default {
    name: "UserProfile",
    beforeRouteEnter: (to,from,next) => {
      console.log('进入路由之前')
      next(vm => {
        vm.getData();//进入路由之前执行该方法
      })
    },
    beforeRouteLeave: (to,from,next) => {
      console.log('进入路由之后')
      next()
    },
    methods: {
      getData: function () {
        this.axios({
          method: 'get',
          url: 'http://localhost:8080/static/mock/data.json'
        }).then((response) => {
          console.log(response)
        })
      }
    }
  }
</script>

<style scoped>

</style>
