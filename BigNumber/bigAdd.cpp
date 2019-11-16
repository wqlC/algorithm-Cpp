/***
 * 大数加法/减法
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct bigNum{
    int data[1000];
    int len;
    int p;      //是否是非负数
    bigNum(){
        memset(data, 0, sizeof(data));
        len = 0;
        p = 1;
    }
}bn;

bn change(char str[]); 
int bigCompare(bn a, bn b);
bn bigAdd(bn a, bn b);
bn bigSub(bn a, bn b);
void bigSwap(bn *a, bn *b);
void bigPrintf(bn c);

int main(int argc, char const *argv[])
{
    bn a, b, c;
    char strA[1000];
    char strB[1000];
    gets(strA);
    a = change(strA);
    gets(strB);
    b = change(strB);

    if(a.p*b.p == 1){//同号，相加
        c = bigAdd(a, b);
    }else{//异号，相减
        c = bigSub(a, b);
    }

    bigPrintf(c);

    return 0;
}

/**
 * 将字符数组转为int数组
 * 其中数字高位放在数组高位
 *      考虑数字正负号
 */
bn change(char str[]){
    bn a;
    int start = 0;
    if(str[0] == '-'){
        a.len = strlen(str)-1;
        start = 1;
        a.p = -1;
    }else
    {
        a.len = strlen(str);
    }
    for(int i=start; i<a.len+start; i++){
        a.data[a.len-i+start-1] = str[i]-'0';
    }
    return a;
}

/**
 * 比较两个数的绝对值大小
 *  如果a>b 返回1
 *  如果a<b 返回-1
 *  如果a=b 返回0
 */
int bigCompare(bn a, bn b){
    if(a.len>b.len){
        return 1;
    }else if (a.len < b.len)
    {
        return -1;
    }else{
        for(int i=a.len-1; i>=0; i--){
            if(a.data[i] > b.data[i]){
                return 1;
            }else if (a.data[i] < b.data[i])
            {
                return -1;
            }
        }
        return 0;
    }
}

/**
 * 大数加法：
 *  从低位开始加
 *  考虑进位
 */
bn bigAdd(bn a, bn b){
    bn c;
    c.p = a.p;
    int carry = 0; //进位
    int temp = 0;
    for(int i=0; i<a.len || i<b.len; i++){
        temp = a.data[i] + b.data[i] + carry;
        c.data[c.len++] = temp%10;
        carry = temp/10;
    }
    if(carry != 0){
        c.data[c.len++] = carry;
    }
    return c;
}

/**
 * 高精度减法
 * 保证是大的减去小的（如果a<b,则交换）
 * 
 * 注意结束时去掉高位的0，同时保证结果至少有1位(例如结果是0000，这样输出的时候只要输出0)
 */

bn bigSub(bn a, bn b){
    bn c;
    if(bigCompare(a, b) == 0){//如果a b的绝对值相等，则直接返回0
        c.len=1;
        c.p = 1;
        c.data[c.len-1] = 0;
        return c;
    }else if (bigCompare(a, b) == -1){
        bigSwap(&a, &b); //用大的减去小的
    }
    if(a.p == 1){//结果的正负号与绝对值大的数的正负号一致
        c.p = 1;
    }else{
        c.p = -1;
    }
   
    for(int i=0; i<a.len; i++){
        if(a.data[i] < b.data[i]){
            a.data[i] += 10;
            a.data[i+1]--;
        }
        c.data[c.len++] = a.data[i]-b.data[i];
    }
    
    while (c.len>1 && c.data[c.len-1] == 0)
    { //去掉高位的0
        c.len--;
    }
    return c;
}

/**
 * 交换a，b
 */
void bigSwap(bn *a, bn *b){
    //交换a, b；
    bn temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 输出加/减结果
 */
void bigPrintf(bn c){
    if(c.p == -1){
        printf("-");
    }
    for(int i=c.len-1; i>=0; i--){
        printf("%d", c.data[i]);
    }
    printf("\n");
}