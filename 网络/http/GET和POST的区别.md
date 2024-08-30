<!--
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-09 11:38:17
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-15 22:55:52
-->
GET和POST方法的区别？

1. GET方法一般用来向服务器请求资源；POST方法一般用来向服务器提交数据。
2. GET方法是安全、幂等、可被缓存的；POST方法不安全、不幂等、一般不可被缓存的。  
3. GET方法请求的参数一般会放在URL中，而POST方法一般把数据放到请求体中，所以POST比GET更安全，但是GET和POST其实都是不安全的，因为HTTP都是明文传输，要提高安全性，只能改为HTTPS。  