#include <iostream>
#include <vector>
using namespace std;

vector<int> static_sliding_window(int arr[], int n, int k, int sum) {
    int current_sum = 0;
    int max_sum = INT_MIN;
    vector<int> res(2, -1); // Initialize with -1
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    if (current_sum == sum) {
        res[0] = 0;
        res[1] = k - 1;
    } else {
        for (int j = 1; j < n - k + 1; j++) {
            current_sum = current_sum - arr[j - 1] + arr[j + k - 1];
            if (current_sum == sum) {
                res[0] = j;
                res[1] = j + k - 1;
                break;
            }
        }
    }
    return res;
}

int main() {
    int arr[7] = {9, 1, 2, 3, 8, 7, 7};
    int window_size = 3;
    int sum = 22;
    vector<int> res = static_sliding_window(arr, 7, window_size, sum);

    if (res[0] != -1 && res[1] != -1) {
        cout << "Subarray with sum " << sum << " found from index " << res[0] << " to " << res[1] << endl;
    } else {
        cout << "Subarray with sum " << sum << " not found" << endl;
    }

    return 0;
}
