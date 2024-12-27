#include<bits/stdc++.h>
using namespace std;

int minSwapsToSort(vector<int>& arr) {
    unordered_map<int, int> mpp;
    int n = arr.size();
    vector<int> v(arr.begin(), arr.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        mpp[arr[i]] = i;
    }
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != v[i]) {
            int ele = arr[i];
            int idx = mpp[v[i]];
            swap(arr[i], arr[idx]);
            mpp[ele] = idx;
            swaps++;
        }
    }
    return swaps;
}
int main(){

    vector<int> arr = {1,2,4,3,5,6};

    cout<<minSwapsToSort(arr)<<endl;

    return 0;
}