http和https的区别？

- http的URL以`http://`开头，https的URL以`https://`开头。
- http通过明文传输，数据都是未加密的，安全性较差。https数据传输过程是加密的，安全性较好。  
- http工作的端口是80，https工作的端口是443。  
- http协议不需要证书，而https协议需要使用CA机构颁发的SSL证书。
- http是基于TCP的，https是基于TCP+SSL协议的。
- 速度