#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    int index = 0;
    while(n != 0){
        res += (n%10)*pow(2 ,index++);
        n/=10;
    }
    cout << res <<endl;
    return 0;
}
