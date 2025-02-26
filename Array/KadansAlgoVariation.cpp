/*

leetcode 1749 - https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

*/

//ya to maximumsubarray sum ya to minimum subarray sum - isme se koi ek hi answer dega 
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
    
            //maxi stores the maximum subarray sum 
            //now we have to find the minimum subarray sum 
            //return the maximum of {absolute value } among them 
    
            int currSubarraySum = nums[0];
            int maxSubarraySum = nums[0];
    
            int minSubarraySum = nums[0];
            int currSubarraySumMin = nums[0];
    
            for(int i=1;i<nums.size();i++){
    
                currSubarraySum =  max(nums[i],currSubarraySum + nums[i]);
                currSubarraySumMin = min(nums[i],currSubarraySumMin + nums[i]);
    
                maxSubarraySum = max(maxSubarraySum,currSubarraySum);
                minSubarraySum = min(minSubarraySum,currSubarraySumMin);
            }
    
            return max(abs(maxSubarraySum),abs(minSubarraySum));
        }
    };