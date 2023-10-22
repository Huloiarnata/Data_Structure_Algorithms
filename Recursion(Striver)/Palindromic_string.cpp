#include <iostream>
using namespace std;
bool checkPalindrome(string s, int initial){
    if(initial>=(s.size()/2)){
        return true;
    }
    if(s[initial]!=s[s.size()-1-initial]){
        return false;
    }
    return checkPalindrome(s,initial+1);
    
}

int main(){
    string c1 = "abba";
    string c2 = "abababa";
    cout<<checkPalindrome(c1, 0)<<endl;
    cout<<checkPalindrome(c2, 0)<<endl;
    return 0;
}