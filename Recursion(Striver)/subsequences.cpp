#include<iostream>
#include <vector>
using namespace std;

void f(int index, vector<int> &res, int a[], int size){
    if(index==size){

        //printing subsequences.
        for(vector<int>::iterator it = res.begin(); it!=res.end(); it++){
            cout<<*it<<" ";
        }
        
        // if empty.
        if(res.empty()){
        cout<<"{}";
        }
        cout<<endl;

        //base condition.
        return;
    }
    // not take or pick.
    f(index+1, res, a, size);

    //take or pick
    res.push_back(a[index]);
    f(index+1, res, a, size);
    res.pop_back();
    
}

int main(){
    int a[3] = {3,1,2};
    int n = 3;
    vector<int> res;
    f(0, res, a, n);
    return 0;
}