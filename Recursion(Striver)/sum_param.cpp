// summation on n using paramatrized function.
#include<iostream>
using namespace std;

void summ(int num, int sum){
    if(num<1){
        cout<<sum<<endl;
        return;
    }
    summ(num-1, sum+num);
}

int main(){
    int n;cout<<"Enter n: ";cin>>n;
    summ(n,0);
    return 0;
}
