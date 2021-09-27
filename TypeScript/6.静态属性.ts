
//静态属性，内建或自定义，无需new即可使用
console.log(Math.round(89.64)); //90
console.log(Math.pow(2, 8)); //256
class MyStaticClass {
  static place = 'Earth';
  static printInfo() {
    console.log('We have only one Earth!');
  }
}
console.log(MyStaticClass.place);
MyStaticClass.printInfo();
          