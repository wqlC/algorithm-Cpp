#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char str[1000];
    gets(str);
    int len = strlen(str);
    for(int i=len; i>=0; i--){
        if(str[i] == ' '){
            printf("%s ", &str[i+1]);
            str[i] = '\0';
        }else if(i == 0){
            printf("%s", &str[i]);
        }
    }
    return 0;
}
