//解构数组
let input = [89,64,65,2018,10];
let [first,second] = input;//注意使用[]
console.log(first);
console.log(second);
let [one,...other] = input;//剩余变量
console.log(...other);
//展开
let newArray = [89,...other,18];
console.log(newArray);
//解构对象
let o = {
    a: "foo",
    b: 12,
    c: "bar"
};
let {a,b} = o;
console.log(a,b);