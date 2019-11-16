#include <iostream>
#include <cstdio>

/**
求1~n的全排列
分治算法
*/
using namespace std;

void generateP(int index);
const int maxn = 11;
int n, p[maxn], hashTable[maxn]={false};    //p是当前的排列， hashTable记录整数x是否已经在P中

int main()
{
    scanf("%d", &n); //输出1~n的全排列
    generateP(1);   //从p[1]开始填
    return 0;
}

void generateP(int index){
    if(index == n+1){
    //递归边界，已经处理完排列的n位
        for(int i=1; i<=n; i++){
            printf("%d", p[i]); //输出当前排列
        }
        printf("\n");
        return ;
    }

    for(int x=1; x<=n; x++){
        //枚举1~n，试图将x填入p[index]
        if(hashTable[x] == false){
            p[index] = x;
            hashTable[x] = true;    //记x已经在P中
            generateP(index+1);     //处理排列的第index+1位
            hashTable[x] = false;   //已经处理完p[index]为x的问题-还原状态
        }
    }
}
