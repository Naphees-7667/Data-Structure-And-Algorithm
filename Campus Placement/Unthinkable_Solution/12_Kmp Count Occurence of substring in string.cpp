/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/

class Solution {
    void lpss(string& needle, vector<int>& lps) {
        int prefix = 0, suffix = 1; 
        while (suffix < needle.size()) {
            if (needle[suffix] == needle[prefix]) {
                lps[suffix] = prefix + 1;
                prefix++;
                suffix++;
            } else {
                if (prefix == 0)
                    suffix++;
                else
                    prefix = lps[prefix - 1];
            }
        }
        return;
    }

public:
    int strStr(string haystack, string needle) {

        int first = 0, second = 0;
        vector<int> lps(needle.size(),0);
        lpss(needle,lps);

        while(first < haystack.size() && second < needle.size()){
            if(haystack[first] == needle[second]){
                first++;
                second++;
            }
            else{
                if(second == 0)first++;
                else second = lps[second-1];
            }
        }

        if(second == needle.size())return first - second;
        return -1;
    }
};