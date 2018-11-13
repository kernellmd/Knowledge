//'use strict';
abc = 'Hello, world';
console.log(abc);

var s = "Hello World!";
var count = 5;
console.log(s);
console.dir(count);
console.dir(s);
//prints "hello world!"

console.log("#################");
var funcs = [];
for (var i = 0; i < 10; i++) {
funcs.push(function() { console.log(i); });
}
funcs.forEach(function(func) {
// 输出数值 "10" 十次
func();
});
