#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int low,int high){
    while(low <= high){
        if(s[low++] != s[high--]){
            return false;
        }
    }
    return true;
}

void solve(string s,int index,int n,vector<string>& ans, vector<vector<string>>& res){
    if(index == n){
        res.push_back(ans);
        return;
    }
    
    for(int i=index;i<n;i++){
        if(isPalindrome(s,index,i)){
            ans.push_back(s.substr(index,i-index+1));
            solve(s,i+1,n,ans,res);
            ans.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> ans;
    int n = s.size();
    solve(s,0,n,ans,res);
    return res;
}

int main() {
    string str = "aab";
    vector<vector<string>> res = partition(str);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}