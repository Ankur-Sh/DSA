//s=bbacba
#include <iostream>
#include <map>
using namespace std;

int countAtMostKDistinct(string s, int k) {
    map<char, int> mpp;
    int left = 0, right = 0;
    int count = 0;

    for (right = 0; right < s.size(); right++) {
        mpp[s[right]]++;

        while (mpp.size() > k) {
            mpp[s[left]]--;
            if (mpp[s[left]] == 0)
                mpp.erase(s[left]);
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

int countExactlyKDistinct(string s, int k) {
    return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
}

int main() {
    string s = "bbacba";
    int k = 3;

    int result = countExactlyKDistinct(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;

    return 0;
}


//optimised code

#include<iostream>
using namespace std;
int main() {
    string s = "bbacba";
    int n=s.size();
    int k = 3;
    int lastseen[3]={-1,-1,-1};
    int cnt=0;
    for(int i=0;i<n;i++){
    lastseen[s[i]-'a']=i;
    if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1) cnt=cnt+1+min({lastseen[0],lastseen[1],lastseen[2]});
    }
     cout<< cnt;
    return 0;
}