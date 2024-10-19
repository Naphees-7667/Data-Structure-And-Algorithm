/* 
* Leetcode - 1636. Sort Array By Increasing frequency

Problem - 
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

! Code - 

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (auto it : nums)
        freq[it]++;

    * Use custom comparator for sorting 

    sort(nums.begin(), nums.end(), [&](int a, int b) {
        if (freq[a] == freq[b]) {
            return a > b;
        }
        return freq[a] < freq[b];
    });

    return nums;
}
* Time  = O(NlogN)
* Space = constant 

*/