#include <iostream>
using namespace std;
void printArray(int arr[], int length){
    for(int i=0; i<length; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int low, int high, int pivot){
    int p_indx = low;
    for(int i=low; i<=high;i++){
        if(arr[i]<=pivot){
            swap(arr[p_indx],arr[i]);
            p_indx++;
        }
    }
    p_indx--;
    return p_indx;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pivot = arr[high]; //pivot: last element.
        int p_idnx = partition(arr, low, high, pivot);
        quicksort(arr,low, p_idnx-1);
        quicksort(arr, p_idnx, high);
    }

}

int main(){
    int arr[5] = {9,8,7,6,5};
    cout<<"Before sorting:  ";
    printArray(arr, 5);
    quicksort(arr, 0, 4);
    cout<<"After sorting:  ";
    printArray(arr, 5);
    return 0;
} 