#include<bits/stdc++.h>
using namespace std;

//brute force approach time - O(N*N)
//space - O(2N)

int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    
    vector<int> knowMe(n,0);
    vector<int> iKnow(n,0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(knowMe[i] == n-1 && iKnow[i] == 0){
            return i;
        }
    }
    
    return -1;
}

//better approach  time - O(N*N) + O(N) 
//space - O(1)
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    int validCandidate,candidate;
    for(int i=0;i<n;i++){
        bool one = false;
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                one = true;
                break;
            }
        }
        if(!one){
            validCandidate++;
            candidate = i;
        }
    }
    
    if(validCandidate != 1){
        return -1;
    }
    
    int oneCount = 0;
    for(int row=0;row<n;row++){
        if(mat[row][candidate] == 1){
            oneCount++;
        }
    }
    
    if(oneCount == n-1){
        return candidate;
    }
    
    return -1;
}

//optimal approach 1- by two pointer time - O(n)and space - constant
int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    
    int top = 0;
    int down = n-1;
    
    while(top < down){
        if(mat[top][down] == 1){
            top++;
        }
        else down--;
    }
    
    int validCelebrity = top;
    
    for(int j=0;j<n;j++){
        if(mat[validCelebrity][j] == 1)return -1;
    }
    
    int oneCount = 0;
    for(int i=0;i<n;i++){
        if(mat[i][validCelebrity] == 1)oneCount++;
        if(oneCount == n){
            return -1;
        }
    }
    return oneCount == n-1 ? validCelebrity : -1;
}

//optimal approach 2 - by stack time - O(n) and space - O(n)

int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    stack<int> st;
    
    for(int i=0;i<n;i++)st.push(i);
    
    while(st.size() > 1){
        int candidate1 = st.top();
        st.pop();
        int candidate2 = st.top();
        st.pop();
        
        if(mat[candidate1][candidate2] == 1){
            st.push(candidate2);
        }
        else st.push(candidate1);
    }
    
    int validCelebrity = st.top();
    st.pop();
    
    int oneCount = 0;
    
    for(int j=0;j<n;j++){
        if(mat[validCelebrity][j] == 1)return -1;
    }
    
    for(int i=0;i<n;i++){
        if(mat[i][validCelebrity] == 1)oneCount++;
        if(oneCount == n){
            return -1;
        }
    }
    return oneCount == n-1 ? validCelebrity : -1;
}

int main(){
    
    return 0;
}