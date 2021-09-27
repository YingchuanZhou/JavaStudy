
class Animal {
    // 当构造函数传入的参数加上了“访问权限控制符”，则同时会声明同名类属性，并赋值
    constructor(public name: string) { }
    protected log(message: string) {
      console.log(message);
    }
    move(distanceInMeters: number = 0) {        
      this.log(`${this.name} moved ${distanceInMeters}m.`);//请注意name来自何处
      this.log('==============');
    }
  }
  
  class Horse extends Animal {
    constructor(name: string) { 
      super(name); // 通过super调用父类构造器
    }
    run(distanceInMeters = 50) { //自己独有的函数
      this.log("Clop, clop..."); 
      super.move(distanceInMeters); // 通过super调用父类方法
    }
  }
  
  class Eagle extends Animal {
    constructor(name: string) { super(name); }
    reborn() { //自己独有的函数
      console.log('Reborn？ It is a joke, hahaha!');
    }
  
  }
  
  let tom: Horse = new Horse("Tommy the Palomino");
  tom.run(8964);
  let sam: Eagle = new Eagle("Sammy the Hawk");
  sam.move(1024);//sam的move函数来自何处？
  sam.reborn();
            