cookie工作原理：客户端第一次访问服务器时，服务器会创建一个cookie其中包含用户的信息，然后将这个cookie发给客户端，下一次客户端再向服务器发起请求时，就会将cookie一并发送给服务器，这样服务器就能识别出客户端了。

---

cookie和的session的区别？

1. cookie存放在客户端（浏览器）上，安全性较低，可能被篡改或窃取；session存放在服务器上，安全性较高。
2. cookie存储上限一般为4K；session没有具体的限制，可以存储的数据量比cookie大。

---

session通常与cookie配合使用（也可以在url中传递sessionID）：当浏览器发送第一次请求给服务器时，服务器会产生成一个session和用来标识这个session的sessionID，session中保存了用户的信息，然后服务器通过设置cookie的方式将这个sessionID发给浏览器，浏览器下次向服务器发送请求时就会顺带发送这个cookie，浏览器接收到cookie后通过sessionID就能找到对应的session，就能识别用户了。


[详解 Cookie 和 Session 关系和区别](https://segmentfault.com/a/1190000014365661)
[Cookie和Session的安全性](https://www.cnblogs.com/damugua/p/12641210.html)