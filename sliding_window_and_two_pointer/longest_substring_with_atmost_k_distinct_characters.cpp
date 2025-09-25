//s=aaabbccd k=2
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int>mpp;
    string s="aaabbccd";
    int k=2;
    int l=0,r=0;
    int maxlen=0;
    while(r<s.size()){
        mpp[s[r]]++;
        while(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++; 
    }
    cout<<maxlen;
    return 0;
}

//optimise code  just change while to if so that it will not trim maxlen it just remove 1 and and move

//s=aaabbccd k=2
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int>mpp;
    string s="aaabbccd";
    int k=2;
    int l=0,r=0;
    int maxlen=0;
    while(r<s.size()){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++; 
    }
    cout<<maxlen;
    return 0;
}