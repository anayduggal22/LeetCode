class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Base Case = Direct initialize dp grid with 0

        vector<vector<int>> dp(prices.size() + 2,vector<int>(2,0));
        // [prices.size()][2(buy OR sell)]
        // Buy = 0
        // Sell = 1
        // size + 2 done as we will access i + 2


        //dp[i] depends on future states. So those future states must already be calculated.So we need to go backwards

        for (int i = prices.size() - 1; i >= 0; i--) {

            // Buying state
            dp[i][0] = max(-prices[i] + dp[i+1][1],
                           0 + dp[i+1][0]);

            // Selling state
            dp[i][1] = max(prices[i] + dp[i+2][0],
                           0 + dp[i+1][1]);

        }

        //Returning Buy
        return dp[0][0];
    }
};