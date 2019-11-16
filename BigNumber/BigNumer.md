# 大整数运算
> 大整数又称为高精度整数，其含义就是 **用基本数据类型无法存储的高精度整数**
## 大整数的存储
使用数组存储即可，对于235813，定义数组d[1000]来存储，数组中每一个存储大整数的每一位，即：d[0]=3,d[1]=1,d[2]=8,d[3]=5,d[4]=3,d[5]=2.
即整数的**高位**存储在数组的**高位**

为了方便获得大整数的长度，一般都会定义一个int型的变量len来记录长度，并和数组d组成结构体，同时为了处理加减法，或者正数加上负数这种情况，还会定义一个p来判断符号
```cpp
struct bigNum{
    int d[1000];
    int len;
    int p;
    //使用构造函数初始话结构体
    bigNum(){
        memset(d, 0, sizeof(d));
        len=0;
        p = 1;
    }
};
```

输入大整数时候，一般都使用字符串输入，然后再把字符串逆序输入**bigNum**中，不过要保证大整数的高位放在数组的高位。
```cpp
struct bigNum change(char str[]){
    struct bigNum a;
    a.len = strlen(str);
    for(int i=0; i<a.len; i++){
        a.d[a.len-i-1] = str[i]-'0';
    }
    return a;
}
```

比较两个大整数的大小：
> 先判断两个整数的长度大小，如果不相等，则以长的为大，否则从高位到地位进行比较，直到出现某一位不等，就可以判断两个数的大小。
```cpp
int compare(struct bigNum a, struct bigNum b){
    // a大、相等、小返回 1，0， -1
    if(a.len>b.len) return 1;
    else if(a.len<b.len) return -1;
    else{
        for(int i=a.len-1; i>=0; i--){
            if(a.d[i]>b.d[i]) return 1;
            else if(a.d[i] < b.d[i]) return -1;
        }
        return 0;
    }
}
```

## 大整数的加法
大数加法基本过程： 从低位开始加，处理进位
```cpp
struct bigNum add(struct bigNum a, struct bigNum b){
    //两个整数都是正数
    struct bigNum c;
    int carry=0;    //进位
    int temp;
    for(int i=0; i<a.len || i<b.len; i++){
        temp = a.d[i]+b.d[i]+carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    if(carry != 0){
        c.d[c.len++] = carry;
    }
    return c;
}
```
> 这样的写法的条件是**两个对象都是非负数**，如果有一方是负数，那么在$change()$去掉负号，采用下面的大整数减法；如果两个都是负数，就都去掉负号后用大整数加法，最后再把负号加回去

## 大整数的减法
大数减法基本过程： 用**大数减小数**（首先判断大小），从低位开始减，注意不够减的时候向高位借！
```cpp
struct bigNum sub(struct bigNum a, struct bigNum b){
    struct bigNum c;
    int temp;
    for(int i=0; i<a.len || i<b.len; i++){
        if(a.d[i]<b.d[i]){
            a.d[i] += 10;
            a.d[i+1]--; 
        }
        c.d[c.len++]=a.d[i]-b.d[i];
    }
    while(c.len-1>=1 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}
```
> 使用sub函数之前要比较两个大整数的**大小**，如果被减数小于减数，需要交换两个变量，然后输出**负号**，再使用sub函数

## 大整数与小整数的乘法
大数乘法基本过程： 用**大数乘小数**（首先判断大小），从低位开始，每次都用大数的低位乘以**完整的小数**，结果**对10取余**放在结果对应的位置，**整除10**进位，
```cpp
struct bigNum multi(struct bigNum a, int b){
    struct bigNum c;
    int temp;
    int carry = 0;
    for(int i=0; i<a.len ; i++){
        temp = a.d[i]*b+carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    while(carry != 0){
        c.d[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}
```
> 如果a或者b中有负号，需要先记录下其负数，然后取他们的绝对值带入函数

## 大整数与小整数的除法
**基本过程：**  
    **从高位开始**，上一步的余数乘以10加上该步的位，得到该步临时的被除数，将其与被除数比较，如果不够除，则该位的商位0，如果够除，则商即为对应的商，余数即为对应的余数。

```cpp
struct bigNum divide(struct bigNum a, int b){
    struct bigNum c;
    int r = 0; //余数
    c.len= a.len;//被除数的每一位和商的每一位一一对应，所以先让商的长度等于被除数的长度
    for(int i=a.len-1; i>=0; i--){//从高位开始除
        r = r*10+a.d[i];
        // if(r<b){//不够除，商0
        //     c.d[i] = 0;
        // }else{
        //     c.d[i] = r/b;
        //     r = r%b;
        // }
        c.d[i] = r/b;
        r = r%b;
    }
    while(c.len-1>= 1 && c.d[len-1] == 0){
        //去除最高位的0，同时至少保留1位最低位
        c.len--;
    }
}
```
