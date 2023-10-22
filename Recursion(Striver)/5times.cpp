#include<iostream>
using namespace std;

//printing recursive function.

void printt(int iter, int n){
    if(iter>n) return;
    printf("RonitKumar\n");
    printt(iter+1,n);
    
}

int main(){
    // user i/p.
    int n;
    cout<<"Enter number: "<<endl; cin>>n;

    //calling recursion function.
    printt(1, n);
    return 0;

}