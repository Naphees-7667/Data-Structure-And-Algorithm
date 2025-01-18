// leetcode 1594. Maximum Non Negative Product in a Matrix
// concept - dp on grids
// link - https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

/*

-- recursion  + memoization solution --

class Solution {

    int n, m;
    int MOD = 1e9 + 7;
    typedef long long ll;
    typedef pair<long long , long long > P;

    vector<vector<P>> dp;

    pair<ll, ll> solve(int row, int col, vector<vector<int>>& grid) {

        if (row == n - 1 && col == m - 1)
            return {grid[row][col], grid[row][col]};

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(dp[row][col] != make_pair(LLONG_MIN,LLONG_MAX)){
            return dp[row][col];
        }

        if (row + 1 < n) {

            auto [rightMax, rightMin] = solve(row + 1, col, grid);

            maxVal = max({maxVal, rightMax * grid[row][col], rightMin * grid[row][col]});

            minVal = min({minVal, rightMax * grid[row][col], rightMin * grid[row][col]});

        }

        if (col + 1 < m) {

            auto [downMax, downMin] = solve(row , col + 1 , grid);

            maxVal = max({maxVal, downMax * grid[row][col], downMin * grid[row][col]});

            minVal = min({minVal, downMax * grid[row][col], downMin * grid[row][col]});

        }

        return dp[row][col] = {maxVal,minVal};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<P>(m,{LLONG_MIN,LLONG_MAX}));

        auto [maxProd , minProd] = solve(0, 0, grid);
        maxProd = maxProd % MOD;

        return maxProd < 0 ? -1 : maxProd;
    }
};

*/

/*

-- tabulation solution --

    int maxProductPath(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<P>(m,{LLONG_MIN,LLONG_MAX}));

        dp[0][0] = {grid[0][0],grid[0][0]};

        for(int col = 1 ; col < m ; col ++){

            dp[0][col] = { grid[0][col] * dp[0][col-1].first , grid[0][col] * dp[0][col-1].second };

        }

        for(int i = 1 ; i < n ; i++ ){

            dp[i][0] = { grid[i][0] * dp[i-1][0].first , grid[i][0] * dp[i-1][0].second};

        }


        for(int row = 1  ; row <  n  ; row++){

            for(int col = 1 ; col < m ; col++){

                ll maxVal = LLONG_MIN;
                ll minVal = LLONG_MAX;

                auto [rightMax, rightMin] = dp[row - 1][col];

                maxVal = max({maxVal, rightMax * grid[row][col], rightMin * grid[row][col]});

                minVal = min({minVal, rightMax * grid[row][col], rightMin * grid[row][col]});

                auto [downMax, downMin] = dp[row] [col -1 ];

                maxVal = max({maxVal, downMax * grid[row][col], downMin * grid[row][col]});

                minVal = min({minVal, downMax * grid[row][col], downMin * grid[row][col]});

                dp[row][col] = { maxVal , minVal};

            }

        }


        auto [maxProd , minProd] = dp[n-1][m-1];
        maxProd = maxProd % MOD;

        return maxProd < 0 ? -1 : maxProd;
    }

*/