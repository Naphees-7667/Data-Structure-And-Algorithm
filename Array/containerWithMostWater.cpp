/* Problem - 
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/

// ! Leetcode - 11. Container with most water 
// Time  = O(n) and space - constant

/* Approach - 
1.here we take two pinter while while traversing always width will decrease (j-i)
2.so if we want max water to store we definately have to store the max height because ye aage kaam aa sakta hai for jyada area.
therefore decrease the pointer on the basis of min heights.
3.calculate area = width * height where we take min(height[i],heoght[j]) because min jitna hi water store hona 
4.return max of all the area.
*/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;

    int maxWater = 0;

    while (i < j) {

        int h = min(height[i], height[j]);

        int w = j - i;

        int area = h * w;

        maxWater = max(maxWater, area);

        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return maxWater;
}