# GCD: Greatst Common Divisor
    gcd(a, b): a和b的最大公约数。

### 欧几里得算法：
> 设a, b均为正整数，则$gcd(a, b) = gcd(b, a\%b)$
#### 证明：
> 证明： 设$a=kb + r$, 其中k和r分别为a除以b得到的商和余数  
则有 $r = a - kb$ 成立  
设d为a和b的一个公约数  
那么由 $r = a - kb$知，d也是r的一个约数  
因此d也是b和r的一个公约数  
又因为 $r = a % b$，知 d为b和a%b的一个公约数  
因此d是a和b的公约数，也是b和a%b的公约数  
由于d是任意，所以有a和b的公约数都是b和a%b的公约数  
因为$a = kb+r$，可以证明b和a%b的公约数都是a和b的公约数  
因此a和b的公约数与b和a%b的公约数相等，所以最大公约数也相等，所以有：$gcd(a, b) = gcd(b, a\%b)  $

### 递归边界
> 0和任意一个整数的最大公约数都是a，可以作为递归边界  
$gcd(a, 0) = a$
### 递归式
> $gcd(a, b) = gcb(b, a\%b) \ \  a>b$

### 求最大公约数
```C
int gcd(int a, int b){
    if(a<b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
```
