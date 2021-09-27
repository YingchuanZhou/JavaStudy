
//类的定义和使用
class MyInfo { //class是关键字，类名默认全部大写首字母
    name: string; //属性
    weather: string; //属性
    
    constructor(name: string, weather: string){ //构造函数，一般用于初始化。如果没有，TS会自动生成一个，以备用new创建类实例时调用。
      this.name = name;
      this.weather = weather;
    }
    printInfo(): void { //其它函数，无返回值
      console.log(`Hello, ${this.name}.`);
      console.log(`Today is ${this.weather}.`);
    }
  }
  
  let myData = new MyInfo('QiGe', 'raining'); //使用new关键字生成对象，即该类的实例
  myData.printInfo();
            