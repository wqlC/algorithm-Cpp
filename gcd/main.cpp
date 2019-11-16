//gcd: greatest common divisor
#include <iostream>
#include <cstdio>

using namespace std;
int gcd(int a, int b);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    if(a>b){
        swap(&a, &b);
    }
    printf("%d\n", gcd(a, b));
    return 0;
}

int gcd(int a, int b){
    return !b?a:gcd(b, a%b);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}