
// leetcode 462 - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

/*
1.sort the array in increasing order 
2.just make all the elements equal to middle elements 

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        int ele = nums[mid];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i == mid)
                continue;
            else if (i < mid) {
                cnt += (ele - nums[i]);
            } else
                cnt += (nums[i] - ele);
        }
        return cnt;
    }
};

*/