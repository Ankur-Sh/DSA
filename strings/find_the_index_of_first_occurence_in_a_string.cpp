/*
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/
#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    if (m == 0) return 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

int main() {
    string haystack, needle;
    cin>>haystack>>needle;
    int result = strStr(haystack, needle);
    if (result != -1)
        cout << "Needle found at index: " << result << endl;
    else
        cout << "Needle not found in haystack." << endl;
    return 0;
}
