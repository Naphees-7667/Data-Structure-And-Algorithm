// leetcode 2658 - https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

// 1st approach - using dfs and same we can also do using bfs
/*
class Solution {
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int n,m;

    int dfs(int i,int j,vector<vector<int>>& grid){

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return 0;
        }

        int maxFish = grid[i][j];
        grid[i][j] = 0;

        for(auto &dir : direction){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            maxFish += dfs(i_,j_,grid);
        }
        return maxFish;
    }

    int bfs(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        int maxFish = grid[i][j];
        grid[i][j] = 0;
        while(!q.empty()){

            auto [row,col] = q.front();

            q.pop();

            grid[row][col] = 0;

            for(auto &dir : direction){

                int i_ = row + dir[0];
                int j_ = col + dir[1];

                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] != 0){

                    q.push({i_,j_});
                    maxFish += grid[i_][j_];
                    grid[i_][j_] = 0;
                }

            }
        
        }
        return maxFish;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int maxFish = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int res = dfs(i, j, grid);
                    maxFish = max(maxFish,res);
                }
            }
        }

        return maxFish;
    }
};
*/

// 2nd approach - using DSU

/*

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    void initSize(vector<vector<int>>& grid) {
        int idx = 0;
        for (auto& it : grid) {
            for (auto& ele : it) {
                size[idx++] = ele;
            }
        }
    }

    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union(int i, int j) {

        int i_parent = find(i);
        int j_parent = find(j);

        if (i_parent == j_parent) {
            return;
        }

        if (size[i_parent] > size[j_parent]) {
            parent[j_parent] = i_parent;
            size[i_parent] += size[j_parent];
        }

        else if (size[i_parent] < size[j_parent]) {
            parent[i_parent] = j_parent;
            size[j_parent] += size[i_parent];
        } 
        else {
            parent[i_parent] = j_parent;
            size[j_parent] += size[i_parent];
        }
    }

    int findMaximum() { 
        return *max_element(begin(size), end(size)); 
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int size = n * m;

        DSU DS(size);

        DS.initSize(grid);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int curr = i * m + j;

                if(grid[i][j] > 0){

                    for(auto &dir : direction){

                        int i_ = i + dir[0];
                        int j_ = j + dir[1];

                        if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] > 0){
                            int curr2  = i_ * m + j_;
                            DS.Union(curr,curr2);
                        }

                    }

                }
            }
        }
        return DS.findMaximum();
    }
};

*/