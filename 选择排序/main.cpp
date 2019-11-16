#include <iostream>

using namespace std;

void selectSort(int num[], int n);

int main(){
    int n;
    int num[1000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    selectSort(num, n);

    for(int i=0; i<n; i++){
        cout << num[i] << " ";
    }
    return 0;
}
void selectSort(int num[], int n){
    // time complex: O(n^2)
    for(int i=0; i<n; i++){
        int k=i;
        for(int j=i; j<n; j++){
            if(num[k]>num[j]){ // inc sort
                k=j;
            }
        }
        //swap two numbers
        int temp = num[i];
        num[i] = num[k];
        num[k] = temp;
    }
}
