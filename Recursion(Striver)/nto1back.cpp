#include <iostream>
using namespace std;

void f(int num){
    if(num==0){
        return;
    }
    cout<< num<< " ";
    f(num-1);
}

int main(){
    int num; cin>>num;
    f(num);
    return 0;
}