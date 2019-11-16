# LCM (Least Common Multiple)
---
LCM: 最小公倍数，$lcm(a, b)$, $a$与$b$中所有公倍数中最小的那个数。

> 最小公倍数是在最大公约数的基础上进行的，当得到$a$与$b$的最大公约数$d$后，可以马上得到$a$与$b$的最小公倍数$a*b/d$,为了防止$a*b$溢出，一般我们写成：$a/d*b$

#### 最小公倍数：
```cpp
int lcm(int a, int b){
    int d = gcd(a, b);
    return a/d*b;
}
int gcd(int a, int b){
    return !b?a, gcd(b, a%b);
}
```
