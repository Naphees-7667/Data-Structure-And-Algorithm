#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2025-01-25

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Step 1: Copy and sort the array
        vector<int> arr = nums;
        sort(begin(arr), end(arr));

        // Step 2: Assign groups based on the limit
        int currGroup = 0;
        unordered_map<int, int> mpp;
        unordered_map<int, list<int>> group;

        // Initialize first element
        group[currGroup].push_back(arr[0]);
        mpp[arr[0]] = currGroup;

        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) > limit) {
                currGroup++;
            }
            group[currGroup].push_back(arr[i]);
            mpp[arr[i]] = currGroup;
        }

        // Step 3: Reconstruct the result array
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int grp = mpp[num];
            result[i] = group[grp].front();
            group[grp].pop_front();
        }

        return result;
    }
};

int main(){
    return 0;
}