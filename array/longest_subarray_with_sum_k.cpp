// [1,2,3,1,1,1,1] k=3
//Code only for positives and negative both
#include<iostream>
#include<map>
using namespace std;
int main(){
map<int,int> preSumMap;
int arr[] = {1, 2, 3, 1, 1, 1, 1};
int k=3;
int n=sizeof(arr)/sizeof(arr[0]);
int sum=0;
int maxLen=0;
for(int i=0;i<n;i++){
sum+=arr[i];
if(sum==k) maxLen=max(maxLen, i+1);
int remaining=sum-k;
if(preSumMap.find(remaining)!=preSumMap.end()){
    int len=i-preSumMap[remaining];
    maxLen=max(maxLen,len);
}
if(preSumMap.find(sum)==preSumMap.end())preSumMap[sum]=i;
}
cout<<maxLen;
return 0;
}

//optimise for positive

#include<iostream>
#include<map>
using namespace std;
int main(){
map<int,int> preSumMap;
int arr[] = {1, 2, 3, 1, 1, 1, 1};
int k=3;
int n=sizeof(arr)/sizeof(arr[0]);
int sum=arr[0];
int maxLen=0;
int left=0;
int right=0;
while(right<n){
while(left<=right && sum>k){
    sum-=arr[left];
    left++;
}
if(sum==k) maxLen=max(maxLen,right-left+1);
right++;
if(right<n)sum+=arr[right];
}
cout<<maxLen;
return 0;
}