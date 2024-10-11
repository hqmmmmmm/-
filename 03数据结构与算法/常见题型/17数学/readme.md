### 快速幂模板
注意有的题目会将取模后的结果相减，此时需要先将结果加MOD再取模。
```cpp
ll fast_power(ll a, ll b, ll p)  // 原理就是 (a * b) % p = (a % p) * (b % p)
{
    ll res = 1;
    a %= p; // 可以先处理一下
    while(b)
    {
        if(b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    
    return res;
}
```

