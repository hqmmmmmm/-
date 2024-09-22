gdb回车 == 再次执行上一次执行的那个gdb命令

## 1.启动和退出gdb

### 1.1命令行传参
set args ...
show args

### 1.2gdb中启动程序
r run           # 如果程序中设置了断点会停在第一个断点的位置, 如果没有设置断点, 程序就执行完了
start           # 阻塞在main函数的第一行，等待输入后续其它 gdb 指令
c continue      # 让程序start之后继续运行, 或者在断点处继续运行

### 1.3退出gdb
q quit


---


## 2.查看代码

l list

### 2.1当前文件
l                     # 从第一行开始显示
l 行号                # 列出这行号对应的上下文代码
l 函数名              # 显示这个函数的上下文内容
list默认只显示10行

### 2.2切换文件
l 文件名:行号
l 文件名:函数名

### 2.3设置显示的行数
set listsize 行数     # 设置显示的行数
show listsize         # 查看一次list显示的行数


---


## 3.断点操作

b break

### 3.1设置断点
b 行号                      # 常规断点                                                   
b 函数名
b 行号 if 变量名 == 某个值   # 条件断点

### 3.2查看断点
i b == info break

### 3.3删除断点
delete == del == d
d 1       # 删除第一个断点
d 2 4 6   # 删除第2，4，6个断点
d 1-5     # 删除第1-5个断点
可以通过info break查看断点的编号

### 3.4设置断点状态
用法与删除断点类似
disable == dis
enable == ena


---


## 4.调试命令

### 4.1继续运行gdb
c continue

### 4.2手动打印信息
p print

打印变量值
p/x i  # 16进制
p/o i  # 8进制

打印变量类型
ptype i


### 4.3自动打印信息
display i      # 每当程序暂停执行（例如单步执行）时，GDB 调试器都会自动帮我们打印出来，而 print 命令则不会。
info display   # 查看自动显示列表
undisplay num  # 取消自动显示
disable display num  # 暂时取消自动显示

### 4.4单步调试
s step   # 单步调试，会进入函数体内部
finish   # 跳出函数体
n next   # 单步调试，不会进入函数体内部
until    # 跳出某个循环体


### 4.5设置变量值

set var 变量名=值



查看堆栈




## gdb调试coredump文件

设置core file size的值
ulimit -c unlimited

当程序崩溃时，会产生coredump文件