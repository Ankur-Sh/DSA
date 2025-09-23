//S=AAABBCCD     k=2
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int> mpp;
    int k;
    string s;
    cin>>k>>s;
    int maxlen=0;
    int maxf=0;
    int j=0;
    int start=0;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
        maxf=max(maxf,mpp[s[i]]);
        while((i-j+1)-maxf>k){
            mpp[s[j]]--;
            j++;
        }
        if((i-j+1)>maxlen){
            maxlen=max(maxlen,i-j+1);
            start=j;
        }
        
    }
    cout<<maxlen<<s.substr(start,maxlen);
    
return 0;
}