#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(int a, int b){
    // 降序
    return a > b;
}

void dataToArray(int n, int A[]){
    for (int  i = 0; i < 4; i++)
    {
        A[i] = n%10;
        n /= 10;
    }
}

int arrayToData(int A[]){
    int res=0;
    for (int i=0; i<4; i++){
        res *= 10;
        res += A[i];
    }
    return res;
}

int main()
{
    int n;
    int A[4] = {0};
    int temp1, temp2;
    scanf("%d", &n);
    while (n!=0 && n != 6174)
    {
        dataToArray(n, A);
        sort(A, A+4, cmp); //降
        temp1 = arrayToData(A);
        
        sort(A, A+4); //升序
        temp2 = arrayToData(A);
        n = temp1 - temp2;
        printf("%04d-%04d=%04d\n", temp1, temp2, n);
    }
    // printf("%04d-%04d=%04d\n", temp1, temp2, n);
    return 0;
}
