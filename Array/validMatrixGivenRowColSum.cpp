/* leetcode - 1605. Find valid matrix given rows and cols sums
you have given rowSum and colSum array and you have to cretae an array from array that satisfy the given condition
*/  

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                    vector<int>& colSum) {

    int n = rowSum.size();
    int m = colSum.size();

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        //take min of row and col sum 
        matrix[i][j] = min(rowSum[i] , colSum[j]);

        rowSum[i] -= matrix[i][j];
        colSum[j] -= matrix[i][j];

        if (rowSum[i] == 0)
            i++; // if row become 0 then go to column and automatically remainning element of that row is filled with 0
        if (colSum[j] == 0) 
            j++; // same for column
    }
    return matrix;
}