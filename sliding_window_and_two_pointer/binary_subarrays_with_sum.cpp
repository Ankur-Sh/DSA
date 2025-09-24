//arr[1,0,0,1,1,0] goal=2;
#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 0, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int goal = 2;

    int cnt1 = 0, cnt2 = 0;

    int l1 = 0, r1 = 0, sum1 = 0;
    while (r1 < n) {
        sum1 += arr[r1];
        while (l1 <= r1 && sum1 > goal) {
            sum1 -= arr[l1++];
        }
        cnt1 += r1 - l1 + 1;
        r1++;
    }
    cout << "Count of subarrays with sum <= goal: " << cnt1 << endl;


    int l2 = 0, r2 = 0, sum2 = 0;
    while (r2 < n) {
        sum2 += arr[r2];
        while (l2 <= r2 && sum2 >= goal) {
            sum2 -= arr[l2++];
        }
        cnt2 += r2 - l2 + 1;
        r2++;
    }
    cout << "Count of subarrays with sum < goal: " << cnt2 << endl;

    cout << "Count of subarrays with sum == goal: " << (cnt1 - cnt2) << endl;

    return 0;
}