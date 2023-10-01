#include <iostream>
using namespace std;
void sort012(int arr[], int n){
    int low = 0; int mid = 0; int high = n-1;
    while(mid<=high){
        switch(arr[mid]){
            case 0:
                swap(arr[low++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high--]);
                break;
        }
            
    }
}
int main(){
    int arr[8] = {0,1,2,2,1,1,0,0};
    sort012(arr, 8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}