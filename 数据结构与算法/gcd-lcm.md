## gcd（最大公约数）求法

### 1.更相减损法
```cpp
int gcd(int a, int b) // 这里好像没考虑b=0的情况
{
    if(a == b) 
        return a;
    if(a > b)
        return gcd(a - b, b);
    if(a < b)
        return gcd(b - a, a);
}

```

### 2.辗转相除法(欧几里得算法)
```cpp
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else 
        return gcd(b, a % b);
}
```

## lcm（最小公倍数）求法
```cpp
int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}
```

| 注意有时要开long long。


[求GCD（最大公约数）的两种方式](https://www.cnblogs.com/fusiwei/p/11301436.html)  
[最大公约数及最小公倍数](https://www.cnblogs.com/fusiwei/p/11454727.html)