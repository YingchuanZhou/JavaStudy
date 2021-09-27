/**
 * 1.使用完整类型定义
 * 2.可选参数
 */
//使用完整函数类型定义
function add(x: number,y: number):number{
    return x+y;
}
//匿名函数
let myAdd = function(x: number, y: number): number{return x+y;};
console.log(myAdd(1,2));
//可选参数
function greeting(firstName: string, lastName?: string){
    if(lastName)
        return `Hello ${firstName} ${lastName}`;
    return `Hello ${firstName}`;
}
console.log(greeting("Zhou"));
console.log(greeting("Zhou","Wang"));
//默认参数
function greeting_2(firstName: string, lastName = 'Wang'){
    return `Hello ${firstName} ${lastName}`;
}
console.log(greeting_2("Zhou"));
console.log(greeting_2("Zhou","Zeng"));
//剩余参数
function greeting_3(firstName: string, ...restName: string[])
{
    return `Hello ${firstName} ${restName.join(' ')}`;
}
//箭头函数
//无参数：函数体只有一行代码，则改行结果为返回值
let greeting1 = () => `Hello TS!`;
console.log(greeting1());
//一个参数，函数体只有一行代码，则执行结果为返回值
let greeting2 = (name: string) => `Hello ${name}`;
console.log(greeting2("Zhou"));
//有两个及以上参数，函数体代码只有一行，则该行结果为函数返回值
let add2 = (a: number, b: number) => a+b;
//两个及以上参数，函数体有多行代码，必须用{}包裹，并且显示给出返回
let add3 = (a: number, b : number) =>{
    let s=a+b;
    return s;
}
console.log(add3(1,2));
