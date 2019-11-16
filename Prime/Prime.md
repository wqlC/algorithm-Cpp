# Prime（素数）
## 素数的定义：
    除了1和他自身之外都不能整除n,则n是素数
## 判素数
### $O(n)$ 复杂度
> 遍历$2,3,···,n-1$,如果存在能被n整除的，则是非素数  
2是素数  
1既不是素数也不是非素数  

```cpp
bool isPrime(int n){
    if(n==2)
        return true;
    for(int i=2; i<n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
```
### $O(\sqrt(n))$复杂度
>在$2,3,···,n-1$如果存在$n$的约数，不妨设为$k$，则有 $n\%k==0$，因为$k*(n/k) == n$，所以$n/k$也是$n$的约数，并且$k$和$n/k$一定有一个小于$\sqrt(n)$，另一个大于$\sqrt(n)$，所以我们只需要判断$n$是否能被$2,3,···,\sqrt(n)$整除就行了

```cpp
bool isPrimt(int n){
    if(n==2) 
        return true;
    for(int i=2; i<int(sqrt(n))); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
```
## 获取素数<b>表</b>
### $O(n\sqrt(n))$复杂度
> 获取$1,2,3,···,n$内的所有素数

```cpp
int findPrime(int n, int A[]){
    int cnt = 0;
    for(int i=0; i<=n; i++){
        if(isPrimt(i)){
            A[cnt++]=i;
        }
    }
    return cnt;
}

bool isPrime(int sqrt(n)){
    if(n == 2){
        return true;
    }
    for(int i=2; i<n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
```

### $O(nloglog(n)$复杂度
> “筛法”求素数表  
对于每一个素数，筛去它的所有倍数，剩下的就都是素数啦
#### 具体过程
1. 2是素数(唯一需要事先确定)，因此筛去所有2的倍数
> **2** **3** ~~4~~ **5** ~~6~~ **7** ~~8~~ **9** ~~10~~ **11** ~~12~~ **13** ~~14~~ **15** ~~16~~
2. 3没有被前面的步骤筛去，因此3是素数，筛去所有3
的倍数
> **2** **3** ~~4~~ **5** ~~6~~ **7** ~~8~~ ~~9~~ ~~10~~ **11** ~~12~~ **13** ~~14~~ ~~15~~ ~~16~~
3. 4已经被步骤1筛去，所以4不是素数
4. 5没有被前面的步骤筛去，因此5是素数。筛去所有5的倍数
> **2** **3** ~~4~~ **5** ~~6~~ **7** ~~8~~ ~~9~~ ~~10~~ **11** ~~12~~ **13** ~~14~~ ~~15~~ ~~16~~

......

最终可以得到1~15内所有的素数
> 2 3 5 7 11 13

### 结论：
    当从小到达到达某一个a数时候，如果这个数没有被前面的步骤筛去，那么a一定是素数。这是因为如果a不是素数，那么a一定有比a小的素因子，而这样在前面的步骤中a一定会被筛掉。所以当枚举到a的时候a没有被筛掉，那么a一定是素数

    “筛”这个动作的实现，可以使用一个 bool数组标记，如果a被筛掉，那么array[a]=true，否则array[a]=false 

```cpp
const int maxN=1001;//比n大1
bool p[maxN]={false};
int prime[maxN];
int cnt=0;
void findPrime(int n){
    for(int i=2; i<n; i++){
        if(p[i]==false){
            prime[cnt++] = i;
            //筛
            for(int j=i+i; j<n; j+=i){
                p[j] = true;
            }
        }
    }
}
```
## 区间内素数
    求M到第N个素数

```cpp
void findPrime(int n){
    for(int i=2; i<n; i++){
        if(p[i]==false){
            prime[cnt++] = i;
            if(cnt>n){
                break;
            }
            //筛
            for(int j=i+i; j<n; j+=i){
                p[j] = true;
            }
        }
    }
}
```

## 质因子分解
$6=2*3=2^1 * 3^1$

$8=2*2*2 = 2^3$

$180 = 2*2*3*3*5=2^2*3^2*5^1$
