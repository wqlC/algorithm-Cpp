#include <iostream>
#include <algorithm>
#include <cstring>
/**
    直接使用C++ std模板库中的std::next_permutation();(字典序全排列)
        首先排序，然后调用std::next_permutation(start, end)
        还有:std::prev_permutation()(逆序全排列)
*/
using namespace std;

int main()
{
    string s = "132";
    sort(s.begin(), s.end());
    do{
        cout << s <<endl;
    }while(next_permutation(s.begin(), s.end()));

    return 0;
}
