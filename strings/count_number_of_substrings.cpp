// s=abc res=6
#include<iostream>
using namespace std;
int main(){
    string s;
    int len=s.size();
    int res=(len*(len+1))/2;
    cout<<res;
    return 0;
}