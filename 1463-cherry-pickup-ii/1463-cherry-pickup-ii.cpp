class Solution {
public:
    int fact(int i, int j1, int j2, vector<vector<vector<int>>>& dp,
             vector<vector<int>>& grid) {
                
        if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) {

            // Out of Bound Case, so return a very small value
            return -1e9;
        }

        if (i == grid.size() - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }


        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        // for j1 from -1to1 with all combination of j2 from -1to1

        int m = -1e9;

        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {

                if (j1 == j2) {
                    m = max(m, grid[i][j1] +
                                   fact(i + 1, j1 + k, j2 + l, dp, grid));
                }

                else {
                    m = max(m, grid[i][j1] + grid[i][j2] +
                                   fact(i + 1, j1 + k, j2 + l, dp, grid));
                }
            }
        }

        return dp[i][j1][j2] = m;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int i = 0;
        int j1 = 0;
        int j2 = grid[0].size() - 1;

        vector<vector<vector<int>>> dp(
            grid.size(), vector<vector<int>>(grid[0].size(),
                                             vector<int>(grid[0].size(), -1)));

        return fact(i, j1, j2, dp, grid);
    }
};