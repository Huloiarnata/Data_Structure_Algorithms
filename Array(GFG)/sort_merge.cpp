#include <iostream>
using namespace std;

void print_array(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int low, int mid, int high){
    int i = low; int j = mid+1; int k = low;
    int temp[20];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++;k++;
    }
    while(j<=high){
        temp[k] = arr[j];
        j++;k++;
    }
    for(i = low;i<=high;i++){
        arr[i] = temp[i];
    }
}

void merge_sort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr ,low, mid, high);
    }
}
int main(){
    int arr[4] = {1,5,3,2};
    int length = sizeof(arr)/sizeof(int);
    cout<<"Before Sorting: "; print_array(arr,length); cout<<endl;
    merge_sort(arr, 0, length-1);
    cout<<"After Sorting: "; print_array(arr,length); cout<<endl;
    return 0;
}