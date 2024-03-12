[跟我一起写Makefie](https://seisman.github.io/how-to-write-makefile/index.html)




clean:
    rm main.o main

这里要说明一点的是， clean 不是一个文件，它只不过是一个动作名字，有点像C语言中的label一样，其冒号后什么也没有，那么，make就不会自动去找它的依赖性，也就不会自动执行其后所定义的命令。要执行其后的命令，就要在make命令后明显得指出这个label的名字。这样的方法非常有用，我们可以在一个makefile中定义不用的编译或是和编译无关的命令，比如程序的打包，程序的备份，等等。




make是如何工作的
make中使用变量
make自动推导