/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){

            if(i > maxi)return false;

            maxi = max(maxi, i + nums[i]);

        }

        return true;
    }
};

/*
Jump Game - 2

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, jumps = 0;

        while (right < n - 1) {
            int farthest = 0;
            for (int i = left; i <= right; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            jumps++;
            left = right + 1;
            right = farthest;
        }

        return jumps;
    }
};