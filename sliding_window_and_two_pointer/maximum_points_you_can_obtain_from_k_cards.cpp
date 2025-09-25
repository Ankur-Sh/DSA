//arr=[6,2,3,4,7,2,1,7,1] k=4 either from left or right you can pick or both but must be consecutive
#include<iostream>
using namespace std;
int main(){
    int arr[]={6,2,3,4,7,2,1,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int lsum=0,rsum=0;
    int maxsum=0;
    int l=0,r=n-1;
        while(l<k){
            lsum+=arr[l];
            l++;
        }
       maxsum=max(maxsum,lsum+rsum);
       l=l-1;
       while(l>=0){
        lsum-=arr[l];
        rsum+=arr[r];
        maxsum=max(maxsum,lsum+rsum);
        l--;
        r--;
       }
       cout<<maxsum;
       return 0;
    
}