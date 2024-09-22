### capacity和size
vector的capacity表示当前vector最多可以容纳多少个元素；size表示vector容器中实际上已经存放了多少个元素。


### reserve
更改vector的容量，使vector至少可以容纳n个元素，可以避免多次不必要的扩容。  
`reserve(n)`，当n大于vector当前的容量，reserve会对vector进行扩容；当n小于vector当前的容量，reserve什么也不会做。


### resize
更改vector的size，