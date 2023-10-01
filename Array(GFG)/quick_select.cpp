#include <iostream>
using namespace std;

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int pivot) {
    
    int p_indx = low;
    for (int i = low; i <= high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[p_indx], arr[i]);
            p_indx++;
        }
    }
    p_indx--;
    return p_indx;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivot = arr[high];
        int pivotIndex = partition(arr, low, high, pivot);
        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    return -1; // Error or not found
}

int main() {
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int k = 3; // Find the 2nd smallest element

    cout << "Array: ";
    printArray(arr, 6);

    int result = quickSelect(arr, 0, 5, 2);

    if (result != -1) {
        cout << "The " << k << "nd smallest element is: " << result << endl;
    } else {
        cout << "Invalid input or element not found." << endl;
    }

    return 0;
}
