/*
8. Given a 2-D matrix. You need to convert it into a linked list matrix 
such that each node is linked to its next right and down node and display it.
*/
#include <iostream>
using namespace std;
int main(){
    // Matrix implementation.
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}