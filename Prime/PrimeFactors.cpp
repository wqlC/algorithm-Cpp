#include <cstdio>
#include <cmath>

struct factor
{
    int x;
    int cnt;
}fac[10];

const int maxN = 100010;
int prime[maxN], pNum = 0;
bool isPrime(int n);
void findPrimes();

int main(int argc, char const *argv[])
{
    findPrimes();
    int n, num=0;
    scanf("%d", &n);
    if(n==1){
        printf("1=1\n");
        return 0;
    }
    printf("%d=", n);

    int sqr = (int)sqrt(1.0*n);
    //枚举 sqrt(n)以内的因子
    for(int i=0; i<pNum && prime[i]<=sqr; i++){
        if(n%prime[i] == 0){
            fac[num].x=prime[i];
            fac[num].cnt = 0;

            while (n%prime[i] == 0)
            {   
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
        if(n==1){
            break;
        }
    }
    if(n != 1){
        fac[num].x = n;
        fac[num++].cnt = 1;
    }

    for(int i=0; i<num; i++){
        if(i>0) printf("*");
        printf("%d", fac[i].x);
        if(fac[i].cnt>1){
            printf("^%d", fac[i].cnt);
        }
    }
    return 0;
}

bool isPrime(int n){
    if(n==1){
        return false;
    }
    int sqr = (int) sqrt(1.0*n);
    for(int i=2; i<=sqr; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void findPrimes(){
    for(int i=1; i<maxN; i++){
        if(isPrime(i)){
            prime[pNum++] = i;
        }
    }
}