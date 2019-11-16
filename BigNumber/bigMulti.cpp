/***
 * 大数*小数
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
bn bigMulti(bn a, bn b);
void bigSwap(bn *a, bn *b);
void bigPrintf(bn c);
int array2Data(bn a);

int main(int argc, char const *argv[])
{
    bn a, b, c;
    char strA[1000];
    char strB[1000];
    gets(strA);
    a = change(strA);
    gets(strB);
    b = change(strB);

    c = bigMulti(a, b);
    bigPrintf(c);

    return 0;
}

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

int bigCompare(bn a, bn b){//比较绝对值大小
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

bn bigMulti(bn a, bn b){
    bn c;
    if(a.p*b.p == 1){//判断输出结果的符号
        c.p = 1;
    }else{//异号
        c.p = -1;
    }
    if(bigCompare(a, b) == -1){
        bigSwap(&a, &b);
    }
    int bData = array2Data(b);
    int carry = 0; //进位
    int temp = 0;
    for(int i=0; i<a.len; i++){
        temp = a.data[i] * bData + carry;
        c.data[c.len++] = temp%10;
        carry = temp/10;
    }
    while(carry != 0){
        c.data[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}


int array2Data(bn a){
    int sum = 0;
    for(int i=a.len-1; i>=0; i--){
        sum *= 10;
        sum += a.data[i];
    }
    return sum;
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