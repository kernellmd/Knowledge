var re = /^\d{3}\-\d{3,8}$/;
console.log(re.test('010-12345')); // true
console.log(re.test('010-1234x')); // false
console.log(re.test('010 12345')); // false
