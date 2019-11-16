#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool isHui(char str[]);
int main(){
    char str[1000];
    gets(str);
    if(isHui(str)){
        cout <<"Yes" << endl;
    }else{
        cout <<"No" <<endl;
    }
    return 0;
}

bool isHui(char str[]){
    int len = strlen(str);
    for(int i=0; i<len/2; i++){
        if(str[i] != str[len-i-1]){
            return false;
        }
    }
    return true;
}
