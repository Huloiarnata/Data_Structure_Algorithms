#include<iostream>
#include<algorithm>
using namespace std;

int static_sliding_window(int arr[], int n, int k){

    int current_sum = 0; int max_sum = INT_MIN;
    for(int i=0; i<k; i++){
        current_sum +=arr[i];
    }
    for(int j = 1; j<n-k+1; j++){
        current_sum = current_sum-arr[j-1]+arr[j+k-1];
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
int main(){
    int arr[7] = {9, 1, 2, 3, 8, 7, 7};
    int window_size = 3;
    int res = static_sliding_window(arr, 7, window_size);
    cout<<"Max sum from subarray of size 3 is: "<<res<<endl;
    return 0;
}