## 文件操作
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

wc



find   查找文件
- find <起始目录> <查找条件> <参数值>
- -name名字查找 -size大小查找 -type文件类型查找

chmod  权限控制
chown  
chgrp  


awk

sed

grep         使用正则表达式搜索文本，通常与管道结合在一起。


tar    对文件进行打包和解打包
- tar -cvf 1.tar 1.txt      仅打包，不压缩
- tar -zcvf 1.tar.gz 1.txt  打包后，以gzip2压缩
- tar -jcvf 1.tar.bz2 1.txt 打包后，以bzip2压缩
- tar -ztvf 1.tar.gz        查看1.tar.gz中的文件
- tar -zxvf 1.tar.gz        解压并解包
- tar -jxvf 1.tar.bz2       解压并解包

gzip  只能压缩单个文件

bzip2








## 网络命令
ping         测试网络连通性
ifconfig     查看和设置网卡配置
route        路由信息查看和配置
ip           网络信息查看与配置

netstat      查看网络连接状态等相关信息
ss           和netstat功能相似，但执行速度比netstat更快 
nslookup     域名解析查询
traceroute   路由追踪，查看数据包在网络上传输时的全部路径
wget         命令行下载文件
curl         多功能工具，可以下载文件，还可以上传文件，发送HTTP请求等等。
tcpdump      数据包分析工具，抓包的



## 系统管理

top        实时查看系统运行情况，如CPU占用率，内存使用率等。

ps         查看进程的详细信息。
- ps aux   查看所有的进程。

lsof       list open file查看进程打开的文件。
- lsof -i         查看网络相关的文件
- lsof -i:端口号   查看占用对应端口号的进程

kill         向进程发送信号。

du 查看文件和目录的磁盘使用情况
df 显示文件系统的磁盘使用情况

free 查看内存使用情况

mount 挂载文件系统     
- mount /dev/hda1 /mnt          将 /dev/hda1 挂在 /mnt 之下
- mount -o ro /dev/hda1 /mnt    将 /dev/hda1 用唯读模式挂在 /mnt 之下




[Linux学习之路基础篇](https://space.bilibili.com/1895975158/channel/collectiondetail?sid=222690&spm_id_from=333.788.0.0)

[一小时掌握Linux核心命令](https://www.yuque.com/zaibaliweigezidemeixi/dopm5h/wh2s4o2dg6096k5p)