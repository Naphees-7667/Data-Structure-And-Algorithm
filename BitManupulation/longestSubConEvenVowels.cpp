// leetcode - 1371 - Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

/*
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
*/

/* code
Optimal Code - 
Pseudo Code for Revision:
1.Initialize mask = 0, result = 0, and a map mpp with mask = 0 at index -1.
2.Loop through each character in the string:
-If the character is a vowel (a, e, i, o, u):
-Toggle the corresponding bit in mask using XOR.
3.If the mask exists in mpp:
-Calculate the length of the substring from the first occurrence of this mask to the current index.
4.Update result if this length is longer than the current result.
5.If the mask doesn't exist in mpp, add it with the current index.
Return result.
*/

// ! property of And bitwise operator - (1&2&3&4&5) is <= 1 because the minimum value of the array is the and of the subarrays. so if you want maximum value then always prefer to make the value maximum among them or the longest subarray the contain that maximum value in the arrays 

#include<bits/stdc++.h>
using namespace std;
int findTheLongestSubstring(string s) {
    unordered_map<int, int> mpp;
    int mask = 0;
    mpp[mask] = -1;
    int result = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            mask = (mask ^ (1 << 0));
        } else if (s[i] == 'e') {
            mask = (mask ^ (1 << 1));
        } else if (s[i] == 'i') {
            mask = (mask ^ (1 << 2));
        } else if (s[i] == 'o') {
            mask = (mask ^ (1 << 3));
        } else if (s[i] == 'u') {
            mask = (mask ^ (1 << 4));
        }

        if (mpp.find(mask) != mpp.end()) {
            result = max(result, i - mpp[mask]);
        } else {
            mpp[mask] = i;
        }
    }
    return result;
}
// Better code - code is similar to longest subarray with sum=0 (prefix sum approach)
int findTheLongestSubstring(string s) {
    unordered_map<string, int> mpp;
    vector<int> state(5, 0);
    string currState = "00000";
    mpp[currState] = -1;
    int result = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            state[0] = (state[0] + 1) % 2;
        } else if (s[i] == 'e') {
            state[1] = (state[1] + 1) % 2;
        } else if (s[i] == 'i') {
            state[2] = (state[2] + 1) % 2;
        } else if (s[i] == 'o') {
            state[3] = (state[3] + 1) % 2;
        } else if (s[i] == 'u') {
            state[4] = (state[4] + 1) % 2;
        }

        currState = "";

        for (int j = 0; j < 5; j++) {
            currState.push_back(state[j] + '0');
        }

        if (mpp.find(currState) != mpp.end()) {
            result = max(result, i - mpp[currState]);
        } else {
            mpp[currState] = i;
        }
    }
    return result;
}