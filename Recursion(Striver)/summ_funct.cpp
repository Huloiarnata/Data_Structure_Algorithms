#include<iostream>
using namespace std;

int m(int num){
    if(num==0){
        return 1;
    }
    return num*m(num-1);
}

int s(int num){
    if(num==0){
        return 0;
    }
    return num+s(num-1);
}

int main(){
    int n;cout<<"Enter n: ";cin>>n;
    cout<<"Sum is: "<<s(n)<<endl;
     cout<<"Priduct is: "<<m(n)<<endl;
    return 0;
}