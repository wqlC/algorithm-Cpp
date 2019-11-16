#include <iostream>

using namespace std;

int main(){
    int a, b;
    int c;
    cin >> a >> b >> c;
    int sum = a+b;

    //½øÖÆ×ª»»
    int res[100]={0};
    int index = 0;
    do{
        res[index++] = sum%c;
        sum /= c;
    }while(sum !=0);
    for(int i=index-1; i>=0; i--){
        cout << res[i];
    }
    cout <<endl;
    return 0;
}
