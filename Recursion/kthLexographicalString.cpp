// subset and permutation pattern - backtracking approach

// leetcode_1415 - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

// better approach

class Solution {
    void solve(string& str, string& res,int k,vector<string>& ans) {
        if(res.size() == k){
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (!res.empty() && str[i] == res.back())continue;
            res.push_back(str[i]);
            solve(str, res,k,ans);
            res.pop_back();
        }
        return;
    }
public:
    string getHappyString(int n, int k) {
        string s = "abc";
        string res = "";
        vector<string> ans;
        solve(s, res,n,ans);
        if(k > ans.size())return "";
        return ans[k - 1];
    }
};

// optimal approach 

class Solution {
    int cnt = 0;
    string ans;
    void solve(string& str, string& res,int n,int k) {
        if(res.size() == n){
            cnt++;
            if(cnt == k){
                ans = res;
            }
            return;
        }

        if(!ans.empty())return;

        for (int i = 0; i < str.size(); i++) {
            if (!res.empty() && str[i] == res.back())continue;
            res.push_back(str[i]);
            solve(str, res,n,k);
            res.pop_back();
        }
        return;
    }
public:
    string getHappyString(int n, int k) {
        string s = "abc";
        string res = "";
        ans = "";
        solve(s, res,n,k);
        if(ans.empty())return "";
        return ans;
    }
};