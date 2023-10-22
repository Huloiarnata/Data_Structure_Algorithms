#include<iostream>
using namespace std;
void rvr(int left, int right, int a[]){
    if(left>=right){
        return;
    }
    swap(a[left], a[right]);
    rvr(left+1, right-1, a);

}
int main(void){
    int a[5] = {4,3,2,1,0};
    rvr(0,4,a);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}