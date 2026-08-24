class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        // [prices.size()][2(buy OR sell)]
        // Buy = 0
        // Sell = 1

        // BASE CASE
        dp[prices.size()][0] = dp[prices.size()][1] = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {

            // Buying state
            dp[i][0] = max(-prices[i] + dp[i + 1][1],
                           0 + dp[i + 1][0]);

            // Selling state
            dp[i][1] = max(prices[i] + dp[i + 1][0],
                           0 + dp[i + 1][1]);
        }

        // Initially we are allowed to buy
        return dp[0][0];
    }
};