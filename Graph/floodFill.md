![alt text](image.png)

// ! Time Complexity: O(NxM + NxMx4) ~ O(N x M)
// ! Space Complexity: O(N x M) + O(N x M)

leetcode - 733. Flood Fill 

que - fill all the cell with the given colour whose initial value is mentioned in questions and each cell have allowd to color in 4 direction 

# Code

```bash

class Solution {

    void bfs(int sr, int sc, int color, vector<vector<int>>& image,
             vector<vector<int>>& res, vector<vector<int>>& vis, int delRow[],
             int delCol[]) {

        int n = image.size();
        int m = image[0].size();

        int initialColor = image[sr][sc];

        queue<pair<int, int>> q;

        vis[sr][sc] = 1;

        res[sr][sc] = color;

        q.push({sr, sc});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++) {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == initialColor && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    res[nrow][ncol] = color;
                }
            }
        }

        return;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> res(n, vector<int>(m, 0));

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = image[i][j];
            }
        }
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        bfs(sr, sc, color, image, res, vis, delRow, delCol);
        return res;
    }
};

```