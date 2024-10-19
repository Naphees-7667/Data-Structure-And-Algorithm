#include <bits/stdc++.h> 
using namespace std;

vector<int> minMaxWindow_Brute(vector<int> a, int n) {
    vector<int> ans(n,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            int num = INT_MIN;
            for(int k=j;k<j+i+1;k++){
                num = max(num,a[k]);
            }
            ans[i] = min(ans[i],num);
        }
    }
    return ans;
}

vector<int> minMaxWindow_Better(vector<int> a, int n) {
    vector<int> ans(n,INT_MAX);
    for(int i=0;i<n;i++){
        int num = INT_MIN;
        int idx = 0;
        for(int j=i;j<n;j++){
            num = max(num,a[j]);
            ans[idx] = min(ans[idx],num);
            idx++;
        }
    }
    return ans;
}

//optimal approach - O(n)
vector<int> minMaxWindow(vector<int> arr, int n) {

    vector<int> ans(n,INT_MAX);
    stack<int> st;

    for(int i=0;i<n;i++){

        while(!st.empty() && arr[i] > arr[st.top()]){
            int compute = arr[st.top()];
            st.pop();
            int nge = i;//next greater element index
            int pge = (st.empty() ? -1 : st.top());//previous greater element index
            int range = nge - pge - 1;
            ans[range-1] = min(ans[range-1],compute);
        }
        
        st.push(i);
    }

    while(!st.empty()){
        int compute = arr[st.top()];
        st.pop();
        int nge = n;
        int pge = (st.empty() ? -1 : st.top());
        int range = nge - pge - 1;
        ans[range-1] = min(ans[range-1],compute);
    }

    for(int i=n-2;i>=0;i--){
        ans[i] = min(ans[i],ans[i+1]);
    }

    return ans;
    
}

int main(){
    vector<int> a = {10,20,15,50,10,70,30};
    int n = a.size();
    vector<int> ans = minMaxWindow(a,n);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}