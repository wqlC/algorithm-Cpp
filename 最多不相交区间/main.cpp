#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Inteval{
    int x;
    int y;
}I[1000];

bool cmp(Inteval a, Inteval b){
    if(a.x != b.x) return a.x > b.x;
    else
        return a.y < b.y;
}

bool cmp2(Inteval a, Inteval b){
    if(a.y != b.y) return a.y < b.y;
    else
        return a.x > b.x;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &I[i].x, &I[i].y);
    }
    sort(I, I+n, cmp);
    for(int i=0; i<n; i++){
        printf("(%d,%d) ", I[i].x, I[i].y);
    }
    printf("\n");
    int lastX = I[0].x;
    printf("(%d,%d) ", I[0].x, I[0].y);
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(I[i].y <= lastX){
            lastX = I[i].x;
            printf("(%d,%d) ", I[i].x, I[i].y);
            cnt++;
        }
    }
    printf("\n");
    printf("%d\n", cnt);

    sort(I, I+n, cmp2);
    for(int i=0; i<n; i++){
        printf("(%d,%d) ", I[i].x, I[i].y);
    }
    printf("\n");
    int lastY = I[0].y;
    printf("(%d,%d) ", I[0].x, I[0].y);
    cnt = 1;
    for(int i=1; i<n; i++){
        if(I[i].x >= lastY){
            lastY = I[i].y;
            printf("(%d,%d) ", I[i].x, I[i].y);
            cnt++;
        }
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}
