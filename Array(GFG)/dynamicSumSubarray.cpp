#include<iostream>
using namespace std;
vector<int> subArraySum(int a[], int size, int sum){
    vector<int> res(2,-1);
    int left = 0; int right = 0; int currentsum =0;
    while(right<size){
        currentsum +=a[right];
        while(currentsum>sum){
            currentsum-=a[left];
            left++;
        }
        if(currentsum == sum){
            res[0]=left;res[1]=right;
            cout<<currentsum;
            break;
        }
        right++;
    }
    return res;
}
int main(){
    int a[9] = {1,4,2,1,2,5,8,8,9};
    int sum = 9;
    vector<int> res = subArraySum(a, 9, sum);
    cout<<"Starting index: "<<res[0]<<" "<<"Ending index: "<<res[1]<<endl;
    return 0;
}