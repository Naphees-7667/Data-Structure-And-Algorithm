#include <bits/stdc++.h> 
using namespace std;

//Btute force approach O(n^3)
vector<int> maxMinWindow_Brute(vector<int> a, int n) {
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            int num = INT_MAX;
            for(int k=j;k<j+i+1;k++){
                num = min(num,a[k]);
            }
            ans[i] = max(ans[i],num);
        }
    }
    return ans;
}

//Better approach O(n^2)
vector<int> maxMinWindow_Better(vector<int> a, int n) {
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        int num = INT_MAX;
        int idx = 0;
        for(int j=i;j<n;j++){
            num = min(num,a[j]);
            ans[idx] = max(ans[idx],num);
            idx++;
        }
    }
    return ans;
}

//optimal approach O(n) 
//hard question  - but includes max area of histogram concept 
//previous smaller index and next smaller index in one pass 
//update the array in only last range range to optimise time 
//at last we traverse and fill the whole array and time takes o(n)

vector<int> maxMinWindow(vector<int> arr, int n) {

    vector<int> ans(n,INT_MIN);
    stack<int> st;

    for(int i=0;i<n;i++){

        while(!st.empty() && arr[i] < arr[st.top()]){
            int compute = arr[st.top()];
            st.pop();
            int nse = i;
            int pse = (st.empty() ? -1 : st.top());
            int range = nse - pse - 1;
            ans[range-1] = max(ans[range-1],compute);
        }
        
        st.push(i);
    }

    while(!st.empty()){
        int compute = arr[st.top()];
        st.pop();
        int nse = n;
        int pse = (st.empty() ? -1 : st.top());
        int range = nse - pse - 1;
        ans[range-1] = max(ans[range-1],compute);
    }

    for(int i=n-2;i>=0;i--){
        ans[i] = max(ans[i],ans[i+1]);
    }

    return ans;
    
}

int main(){
    vector<int> a = {10,20,15,50,10,70,30};
    int n = a.size();
    vector<int> ans = maxMinWindow(a,n);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}