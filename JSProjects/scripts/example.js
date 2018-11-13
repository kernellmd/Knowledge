// JavaScript source code

/*
 * 块级注释
 */

var message = "Hello World!"
var message2
var bool_test = null;
var testAsBoolean = Boolean(bool_test);
var result = Number.MAX_VALUE + Number.MAX_VALUE;
var num = parseInt("070");
var num1 = parseInt("070", 8);
var num2 = parseInt("0xA");
var num3 = parseInt("AF", 16);

function sayHi() {
    alert(num);
    alert(num1);
    alert(num2);
    alert(num3);
    //alert(Number.NEGATIVE_INFINITY);
    //alert(Number.POSITIVE_INFINITY);
    //alert(isFinite(result));
    //alert(Number.MAX_VALUE);
    //alert(Number.MIN_VALUE);
    //if (message) {  //自动执行Boolean()函数
    //    alert("Value is ture");
    //}
    //alert(testAsBoolean);
    //alert(typeof hello);  //hello变量为声明,"undefined"
    //alert(typeof message2);  //message2为未初始化的变量,"undefined"
    //alert(typeof message);  //typeof是一个操作符而不是函数，所以可以不使用括号
    //alert(typeof(message));  //"string"
    //alert(typeof(59))   //"number"
    //alert(typeof (null));  //"object"
    //alert(typeof sayHi);  //"function"
}

//window.onload = sayHi();
