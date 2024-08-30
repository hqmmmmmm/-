## 文件操作命令
ls           查看当前路径下的文件和目录  
cd           切换当前目录  
pwd          显示当前工作目录  

cp           复制文件或目录(-r)  
mv           移动文件或目录

touch        创建文件（如果文件不存在则创建，如果文件存在则修改最后访问日期）  
- touch filename{1..30} 同时创建filename1 filename2 filename3 ...   

mkdir        创建目录  
- mkdir dir{1..30} 同时创建dir1 dir2 dir3 ...
- mkdir -p 父目录不存在时创建父目录，-p即parents  

rm           删除文件或目录
- rm -f    force的意思，强制删除
- rm -r    递归删除，删除目录


cat          输出文件内容  
- cat -n    显示行号

head    显示文件内容的头部
- head -n   显示前n行

tail   显示文件内容的尾部
- head -n   显示后n行
- head -f   follow的意思，实时显示最新增加到文件末尾的行，一般用于实时跟踪日志

more  分屏读取文件内容  
- 前进一行  回车键
- 前进一屏  空格键
- 退出     q键（quit）

less  更强大的分屏阅读
- 前进或后退一行  支持使用方向键 回车键
- 前进或后退一页  空格pgdn pgup b键
- more只能向下翻屏，使用less时，则可以随意上下翻看文件。
- cat和more会加载文件全部内容，less只加载要看的内容，看大文件有用。



chmod  
chown  
chgrp  

find


grep         使用正则表达式搜索文本，通常与管道结合在一起。


tar          对文件进行打包

wc

top          实时查看系统运行情况，如CPU占用率，内存使用率等。

ps           查看系统中所有进程的状态信息。

kill         向进程发送信号。

awk


## 网络命令






查看系统

printenv
env


[Linux学习之路基础篇](https://space.bilibili.com/1895975158/channel/collectiondetail?sid=222690&spm_id_from=333.788.0.0)



## 进程控制
```cpp
tee   # 
```
