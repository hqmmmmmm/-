### 安装perf
```shell
sudo apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`
```
### 使用perf对系统CPU时间做采样
```shell
sudo perf record -F 99 -g ./main -- sleep 60
```

### 生成火焰图
```shell
# 利用这个开源工具可以将报告生成可视化的svg图片，更容易查看对应的CPU开销时间和调用栈深度。
git clone --depth 1 https://github.com/brendangregg/FlameGraph.git  
sudo apt install  -y perl

# 生成火焰图的脚本
sudo perf script -i perf.data &> perf.unfold
./FlameGraph/stackcollapse-perf.pl perf.unfold &> perf.folded
./FlameGraph/flamegraph.pl perf.folded > perf.svg
```

[Perf性能分析](https://ym9omojhd5.feishu.cn/wiki/Z5oQwgwuriISOPksjmscBhyInsh)  
[【火焰图🔥】Linux C/C++性能优化分析工具Perf使用教程](https://www.bilibili.com/video/BV1hg4y1o7Sb)