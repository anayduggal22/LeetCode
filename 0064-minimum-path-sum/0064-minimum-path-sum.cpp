class Solution {
public:
    int fact(int n, int m, vector<vector<int>>& grid) {

        vector<int> prev(m + 1);

        for (int i = 0; i <= n; i++) {

            vector<int> curr(m + 1);

            for (int j = 0; j <= m; j++) {

                if (i == 0 && j == 0) {
                    // Base Case
                    curr[j] = grid[i][j];
                }

                else {

                    int up = 1e9;   // Should be default big
                    int left = 1e9; // Should be default big

                    if (i > 0) {
                        up = grid[i][j] + prev[j];
                    }

                    if (j > 0) {
                        left = grid[i][j] + curr[j - 1];
                    }

                    curr[j] = min(up, left);
                }
            }
            prev = curr; // IMPORTANT 
        }

        return prev[m]; // IMPORTANT
    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        return fact(n - 1, m - 1, grid);
    }
};