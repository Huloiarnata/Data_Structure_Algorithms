#include<iostream>
using namespace std;

void n1(int num){
    if(num==0){
        return;
    }
    cout<<num<<" ";
    n1(num-1);
}

int main(){
    int n;cout<<"Enter number: ";cin>>n;
    n1(n);
    return 0;
}