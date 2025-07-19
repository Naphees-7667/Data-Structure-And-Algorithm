/*
Palindromic Substrings

Problem statement
You have been given a string STR. Your task is to find the total number of palindromic substrings of STR.

Example :
If the input string is "abbc", then all the possible palindromic substrings would be: ["a", "b", "b", c", "bb"] and hence, the output will be 5 since we have 5 substrings in total which form a palindrome.
Note :
A string is said to be a 'Palindrome' if it is read the same forwards and backwards. 
For example, “abba” is a palindrome, but “abbc” is not.

A 'Substring' is a contiguous sequence of characters within a string. 
For example, "a", "b", "c", "ab", "bc", "abc" are substrings of "abc".

*/

#include<bits/stdc++.h>

int countPalindrome(int left, int right, string &input){

    int cnt = 0;

    while(left >= 0 && right < input.size() && input[left] == input[right]){
        cnt++;
        left--;
        right++;
    } 

    return cnt;

}

int palindromicSubstrings(string input)
{
    int count = 0;

    for(int i = 0; i < input.size(); i++){
        // count odd length palindrome
        count += countPalindrome(i, i, input);
        // count even length palindrome
        count += countPalindrome(i, i + 1, input);
    }

    return count;
}

/*

Longest Palindromic Substring

You are given a string 'str' of length 'N'.

Your task is to return the longest palindromic substring. If there are multiple strings, return any.

A substring is a contiguous segment of a string.


For example :
str = "ababc"

The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. 

There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.

*/

#include <bits/stdc++.h>
using namespace std;

string expandAroundCenter(int left, int right, const string &s) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalinSubstring(string s) {
    string longest = "";
    
    for (int i = 0; i < s.size(); ++i) {
        // Odd length
        string odd = expandAroundCenter(i, i, s);
        if (odd.size() > longest.size()) longest = odd;

        // Even length
        string even = expandAroundCenter(i, i + 1, s);
        if (even.size() > longest.size()) longest = even;
    }
    return longest;
}