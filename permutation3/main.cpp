#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
void permute(char* a, int left, int right);
void swap(char *x, char *y);
bool isAppeared(char* str, char t, int begin, int end);
int cnt = 0;
int main()
{
    char str[1000];
    gets(str);
    int len = strlen(str);

    permute(str, 0, len-1);
    printf("%d\n", cnt);
    return 0;
}

void permute(char* a, int left, int right){
    if(left == right){
       printf("%s\n", a);
       cnt++;
    }else{
        for(int i=left; i<=right; i++){
            //判断是否是重复的
            /**
                对字符串进行全排列,注意该函数处理了字符重复的情况,字符重复的情况有两种：
                1. str[i]本身和后面的str[k]相同
                2. str[k]在k+1到i-1的下标之间已经出现过(用IsAppeared()函数去判断)
            */
            if(i!=left && (a[i]==a[left] || isAppeared(a, a[i], left+1, i-1))){
                continue;
            }
            swap((a+left), (a+i));
            permute(a, left+1, right);
            swap((a+left), (a+i));
        }
    }
}

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

bool isAppeared(char* str, char t, int begin, int end){
    for(int i=begin; i<=end; i++){
        if(t==str[i]){
            return true;
        }
    }
    return false;
}
