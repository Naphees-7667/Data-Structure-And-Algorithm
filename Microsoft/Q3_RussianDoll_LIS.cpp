#include<bits/stdc++.h>
using namespace std;

// leecode 354 - https://leetcode.com/problems/russian-doll-envelopes/description/


// Time complexity - NLogN

// 1.sort according to width in increasing order but when width is  equal then sort height in decreasing order 
// 2.return lIS(longest increasing subsequence) according to height of envelopes

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int longestIncreasingSubsequence(vector<vector<int>>& arr) {

        int n = arr.size();
        vector<int> res;
        res.push_back(arr[0][1]);

        for (int i = 1; i < n; i++) {
            if (arr[i][1] > res.back()) {
                res.push_back(arr[i][1]);
            } else {
                int idx = lower_bound(res.begin(), res.end(), arr[i][1]) -
                          res.begin();
                res[idx] = arr[i][1];
            }
        }

        return res.size();
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        return longestIncreasingSubsequence(envelopes);
    }
};