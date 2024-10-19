// ! T.C = O(n logn) + O(m logm) - for sorting
// ! S.C = O(1) Constant

// * Leetcode - 3218. Minimum Cost to cut the board/cake

/* Approach - 
1.horizontal cuts depends upon veticalPieces and vice versa
*/

#include<bits/stdc++.h>
using namespace std;

int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {

    sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
    sort(verticalCut.begin(),verticalCut.end(),greater<int>());

    int horizontalIndex = 0 , verticalIndex = 0;
    int horizontalPieces = 1 , verticalPieces = 1;

    int totalCost = 0;

    while(horizontalIndex < horizontalCut.size() && verticalIndex < verticalCut.size()){
        if(horizontalCut[horizontalIndex] > verticalCut[verticalIndex]){
            totalCost += horizontalCut[horizontalIndex]*verticalPieces;
            horizontalPieces++;
            horizontalIndex++;
        }
        else{
            totalCost += verticalCut[verticalIndex]*horizontalPieces;
            verticalPieces++;
            verticalIndex++;
        }
    }

    while(horizontalIndex < horizontalCut.size()){
        totalCost += horizontalCut[horizontalIndex]*verticalPieces;
        horizontalIndex++;
    }

    while(verticalIndex < verticalCut.size()){
        totalCost += verticalCut[verticalIndex]*horizontalPieces;
        verticalIndex++;
    }

    return totalCost;
}