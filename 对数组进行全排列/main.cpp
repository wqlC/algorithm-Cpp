#include <iostream>
#include <cstdio>

using namespace std;
void swap(int num[], int x, int y);
void perm(int num[], int p, int q, int n);
void printNum(int num[],int n);
bool isAppeared(int num[], int target, int left, int right);

int count  = 0;

int main()
{
    int num[100];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
    }

    perm(num, 0, n-1, n);
    printf("%d\n", count);
    return 0;
}

void perm(int num[], int p, int q, int n){
    if(p == q){
        printNum(num, n);
        count++;
    }else{
        for(int i=p; i<=q; i++){
            //考虑重复的情况
            if((i!=p) && (isAppeared(num, num[i], p, i-1))){
                continue;
            }
            swap(num, p, i);
            perm(num, p+1, q, n);
            swap(num, p, i);
        }
    }
}

void swap(int num[], int x, int y){
    int temp = num[x];
    num[x] = num[y];
    num[y] = temp;
}
void printNum(int num[],int n){
    for(int i=0; i<n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}
bool isAppeared(int num[], int target, int left, int right){
    for(int i=left; i<= right; i++){
        if(num[i] == target){
            return true;
        }
    }
    return false;
}
