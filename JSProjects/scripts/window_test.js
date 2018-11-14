'use strict';
var str = "Hello Window!";

function foo() {
    alert('foo');
}

foo(); // 直接调用foo()
window.foo(); // 通过window.foo()调用
alert(window.str);
