#include <iostream>
#include <cstdio>

using namespace std;
void findPrime(int n);

const int maxN=100001;
int prime[maxN];
int cnt = 0;
bool p[maxN]={false};

int main(int argc, char const *argv[])
{
    int m, n;
    int count=0;
    scanf("%d%d", &m, &n);
    findPrime(maxN);
    for(int i=m-1; i<n; i++){
        count++;
        printf("%d", prime[i]);
        if(count%10!=0 && i<n){
            printf(" ");
        }else
        {
            printf("\n");
        }
        
    }
    printf("\n");
    return 0;
}

void findPrime(int n){
    for(int i=2; i<n; i++){
        if(p[i] == false){
            prime[cnt++] = i;
            for(int j=i+i; j<n; j+=i){
                p[j] = true;
            }
        }
    }
}