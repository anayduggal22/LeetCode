class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {

        // dp[i][j] tells whether the point (i, j) has already been counted
        vector<vector<int>> dp(203,vector<int>(203, 0));

        int ans = 0;

        for (int l = 0; l < circles.size(); l++) {

            int x = circles[l][0];
            int y = circles[l][1];
            int r = circles[l][2];

            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {

                    int dx = x - i;
                    int dy = y - j;

                    int d = dx * dx + dy * dy;

                    if (d <= r * r) {

                        // Count the point only once
                        if (!dp[i][j]) {
                            dp[i][j] = 1;
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};