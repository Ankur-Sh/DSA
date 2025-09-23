//S=AAABBCCD     k=2

//Brute Force  --> O(nlogn) logn for accessing in map
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

//more optimised  Access time O(1)
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int k;
    string s;
    vector<int>freq(26,0);
    cin>>k>>s;
    int maxlen=0;
    int maxf=0;
    int j=0;
    int start=0;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'A']++;
        maxf=max(maxf,freq[s[i]-'A']);
        while((i-j+1)-maxf>k){
            freq[s[j]-'A']--;
            j++;
        }
        if(i-j+1>maxlen){
            maxlen=i-j+1;
            start=j;
        }
    }
    cout<<maxlen<<s.substr(start,maxlen);
    
return 0;
}