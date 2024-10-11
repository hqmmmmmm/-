编译期

std::is_same<T1, T2>
std::is_same_v<T1, T2>    std::is_same<T1, T2>::value


std::is_same_v<T1, std::decay_t<T2>>


std::is_same_v<T1, decltype(expr)>

std::decay_t<>

std::is_same实现


https://www.coder.work/article/6807853