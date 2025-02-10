#include<bits/stdc++.h>
using namespace std;
int longestKSubstr(string &s, int k) {
    
    unordered_map<char,int> mpp;
    int i = 0, j = 0, ans = -1;

    while(j < s.size()){
        // insert the char -> do according to condition
        mpp[s[j]]++;

        // make the window valid 
        while(mpp.size() > k){
            mpp[s[i]]--;
            if(mpp[s[i]] == 0){
                mpp.erase(s[i]);
            }
            i++;
        }

        j++;
        // update the answer  
        ans = max(ans,j-i);
    }
    return mpp.size() == k ? ans : -1;
}