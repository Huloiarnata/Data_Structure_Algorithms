#include <iostream>
using namespace std;
class Solution{
public:
    int firstOccurence(int arr[], int n, int key){
        int begin = 0;
        int end = n - 1;
        int start = -1; // Initialize with an invalid index
        while(begin <= end){
            int mid = begin + (end - begin) / 2;
            if(arr[mid] == key){
                start = mid;
                end = mid - 1; // Update the end to search for the first occurrence
            }else if(arr[mid] < key){
                begin = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return start;
    }
    
    int lastOccurence(int arr[], int n, int key){
        int begin = 0;
        int end = n - 1;
        int last = -1; // Initialize with an invalid index
        while(begin <= end){
            int mid = begin + (end - begin) / 2;
            if(arr[mid] == key){
                last = mid;
                begin = mid + 1; // Update the begin to search for the last occurrence
            }else if(arr[mid] < key){
                begin = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return last;
    }
    
    int count(int arr[], int n, int x) {
       int s_indx = firstOccurence(arr, n, x);
       int l_indx = lastOccurence(arr, n, x);
       int cnt = l_indx - s_indx + 1; // Add 1 to include the last occurrence
       return cnt;
    }
};
int main() {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        Solution ob;
        int ans = ob.count(arr, n, x);
        cout << ans << "\n";
    return 0;
}