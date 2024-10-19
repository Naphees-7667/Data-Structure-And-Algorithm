/*
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

Input -
A = [1, 4, 2, 3]
B = [2, 5, 1, 6]
C = 4
Output = [10, 9, 9, 8]
*/
//Time - O(NlogN) and Space - O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> maximumSumCombination(vector<int> &A, vector<int> &B, int C) {
    int N = A.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> st;
    vector<int> ans;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    pq.push({A[N-1] + B[N-1],{N-1,N-1}});
    st.insert({N-1,N-1});
    
    while(C--){
        
        auto p = pq.top();
        int sum = p.first;
        int i = p.second.first;
        int j = p.second.second;
        
        ans.push_back(sum);
        pq.pop();
        
        if(st.find({i-1,j}) == st.end()){
            pq.push({A[i-1] + B[j],{i-1,j}});
            st.insert({i-1,j});
        }
        
        if(st.find({i,j-1}) == st.end()){
            pq.push({A[i] + B[j-1], {i,j-1}});
            st.insert({i,j-1});
        }
    }
    
    return ans;
}
int main(){

    vector<int> A = {1,2,3,4};
    vector<int> B = {1,2,3,4};
    int C = 2;
    vector<int> ans = maximumSumCombination(A,B,C);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}