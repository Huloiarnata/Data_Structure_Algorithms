#include<iostream>
using namespace std;

void oneTon(int i, int num){
    if(i > num){
        return;
    }
    cout<<i<< " ";
    oneTon(i+1, num);

}

int main(){
    int n;cout<<"Enter number n: "; cin>>n;
    oneTon(1, n);
    return 0;
}