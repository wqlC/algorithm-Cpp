#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b);
void swap(int *a, int *b);
int lcm(int a, int b, int d);

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    if(a<b){
        swap(&a, &b);
    }
    int d = gcd(a, b);
    printf("%d\n", lcm(a, b, d));
    return 0;
}

int gcd(int a, int b){
    return !b? a: gcd(b, a%b);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int lcm(int a, int b, int d){
    return a/d*b;
}