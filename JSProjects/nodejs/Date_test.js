var now = new Date();
console.log(now); // Wed Jun 24 2015 19:49:22 GMT+0800 (CST)
console.log(now.getFullYear()); // 2015, 年份
console.log(now.getMonth()); // 5, 月份，注意月份范围是0~11，5表示六月
console.log(now.getDate()); // 24, 表示24号
console.log(now.getDay()); // 3, 表示星期三
console.log(now.getHours()); // 19, 24小时制
console.log(now.getMinutes()); // 49, 分钟
console.log(now.getSeconds()); // 22, 秒
console.log(now.getMilliseconds()); // 875, 毫秒数
console.log(now.getTime()); // 1435146562875, 以number形式表示的时间戳
