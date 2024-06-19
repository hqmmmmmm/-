set 定义变量
    - set(SRC_LIST main.cc tool.cc)
    - set(CMAKE_CXX_STANDARD 17)   设置C++标准
    - set(EXECUTABLE_OUTPUT_PATH  ../)  这个宏不可以小写, CMakeLists中的.路径是makefile最终生成的路径。


CMake依赖文件要写头文件吗？




## CMAKE常用变量

PROJECT_BINARY_DIR             项目的二进制文件目录，即编译后的可执行文件和库文件的输出目录
PROJECT_SOURCE_DIR             项目的源文件目录
CMAKE_BINARY_DIR               当前CMake运行的二进制文件目录，通常和PROJECT_BINARY_DIR是同一个目录
CMAKE_SOURCE_DIR               顶级CMakeLists.txt所在的路径, 通常和PROJECT_SOURCE_DIR相同
CMAKE_CURRENT_SOURCE_DIR       当前CMakeLists.txt所在的路径


## CMAKE常用命令
```cmake
# 让源代码能够访问CMakeLists.txt中的变量数据，如版本号VERSION.
configure_file(<inputfile> <outputfile>)    

# 将 <dir> 下的源文件都保存在 变量 <variable> 中
aux_source_directory(<dir> <variable>)

# 实现嵌套CMakeLists.txt
add_subdirectory(<source_dir>)        

# 生成静态库（默认）或动态库
add_library(<name> [STATIC | SHARED | MODULE] [<source>...])     

# 将库链接到稍后添加的所有目标（不推荐使用）
link_libaries

# 将指定目录添加到编译器的头文件搜索路径下（不推荐使用）
include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])

# 为指定目标链接指定库（推荐使用）
target_link_libraries(<target> [PRIVATE | PUBLIC | INTERFACE] <item>... ...)     

# 指定头文件搜索路径，并将搜索路径关联到一个target上（推荐使用）
target_include_directories(mylib [[PRIVATE | PUBLIC | INTERFACE]] <path>)

# 与前面的类似，只不过是添加库的搜索路径
link_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])

# 与前面的类似，只不过是添加库的搜索路径 
target_link_directories(mylib [[PRIVATE | PUBLIC | INTERFACE]] <path>)

```

链接库设为可选  #cmakedefine, option, if条件判断


## 参考
[CLion开发环境配置完全解析](https://juejin.cn/post/7184793007302901820#heading-11)  
