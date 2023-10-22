#include<iostream>
using namespace std;
/*nth fibonacci using multiple recurssion*/

int f(int n){
    if(n<=1) return n;
    return f(n-1)+f(n-2);
}

int main(){
    int nth;cout<<"Enter nth position: ";cin>>nth;
    cout<<"Nth element in series is: "<<f(nth)<<endl;
}