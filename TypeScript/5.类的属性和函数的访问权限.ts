
//访问权限
class MyInfo2 { //class是关键字，类名默认全部大写首字母
    public name: string; //public属性，可省略
    private _weather: string; //私有属性，习惯以_开头进行命名
    
    constructor(name: string, weather: string){ //构造函数，一般用于初始化
      this.name = name;
      this._weather = weather;
    }
    printInfo(): void { //其它函数
      this._test();
      console.log(`Hello, ${this.name}.`);
      console.log(`Today is ${this._weather}.`);
    }
    private _test(): void {
      console.log('You can not call me outside!');
    }
  }
 let myData2 = new MyInfo2('QiGe', 'raining'); //使用new关键字生成对象
//   console.log(myData._weather); //error!
//   myData2._test(); //error
  myData2.printInfo();
            