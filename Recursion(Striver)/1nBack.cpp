
//using backtracking use i-1
#include<iostream>
using namespace std;
void prin(int i, int num){

    if(i<1){
        return;
    }
    prin(i-1,num);
    cout<< i<< " ";
}

int main(){

    int n;cout<<"Enter number: ";cin>>n;
    prin(n,n);
    return 0;
}