/*
leetcode 287. Find the duplicate number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

constraints =>  1 <= nums[i] <= n where n is the size of arr

*/

/*
If there is this type of constraints then definately atleast think about traversing the array from indices and do some computations (1 <= nums[i] <= n)

Approach : How I identify horse and tortoise algorithm
1.Duplicacy 
2.Traverse through indices (1 <= nums[i] <= n)

Then this about using slow and fast pointer of ll concept-
1.slow = slow->next and fast = fast->next->next
2.when they meet then we it is confirm that ll has cycle
3.start fast again from starting and move slow and fast now on step
4.when they meet that is our duplicate element
*/

// code
#include<bits./stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    //detect the cycle
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);//* time->liner and space->constant

    fast  = nums[0];
    //find the repeating number
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}