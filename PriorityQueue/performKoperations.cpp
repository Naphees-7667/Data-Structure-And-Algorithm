#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n,int k){
    priority_queue<int>pq;
    for(auto it : arr){
        pq.push(it);
    }

    int sum = 0;

    while(k--){
        int top = pq.top();
        int curr = top/2;
        pq.pop();
        pq.push(curr);
    }

    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    return sum;
}
int main(){

    int n,k;
    cin>>n>>k;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }    

    int ans = solve(arr,n,k);

    cout<<"Sum = "<<ans<<endl;

    return 0;
}