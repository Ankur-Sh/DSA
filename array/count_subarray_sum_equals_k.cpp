//arr[]=[1,2,3,-3,1,1,1,4,2,-3] k=3

#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,-3,1,1,1,4,2,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int cnt=0;
    for(int i=0;i<n;i++){
         int sum=0;
        for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> mpp;
    int arr[]={1,2,3,-3,1,1,1,4,2,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int cnt=0;
    int sum=0;
    mpp[0]=1;
    for(int i=0;i<n;i++){
       sum+=arr[i];
       int preSum=sum-k;
       if(mpp.find(preSum)!=mpp.end()) cnt+=mpp[preSum];
       mpp[sum]++;
    }
    cout<<cnt;
    return 0;
}

