#include <iostream>
using namespace std;
void clockwise_rotate(int a[], int k){
    vector<int> tmp;
    int len = sizeof(a)/sizeof(int);
    for(int i = 0; i<k; i++){
        tmp[i] = a[len-k+i];
    }
    for(int i = k; i<len; i++){
        tmp[i] =  a[i-k];
    }
    for(int i = 0; i<len; i++){
        a[i] = tmp[i];
    }
}
int main(){
    int arr[5] = {4,3,1,2,8};
    int k = 2;
    clockwise_rotate(arr, k);
    int size = sizeof(arr)/sizeof(int);
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}