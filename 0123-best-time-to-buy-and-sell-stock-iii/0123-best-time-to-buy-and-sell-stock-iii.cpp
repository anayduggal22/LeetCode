class Solution {
public:

    int fact(vector<int>& prices, vector<vector<vector<int>>>& dp, int n, int buy, int cap){

        // Base Case 
        if(n == prices.size() || cap == 0){
            return 0;
        }

        if(dp[n][buy][cap] != -1){
            return dp[n][buy][cap];
        }

        int profit = 0;

        // For buy, we will subtract price
        // For sell, we will add price

        if(buy == 0){
            // We can either buy, or go to next index
            // For buy, we will turn 0 to 1, so that from now on we want to sell
            // Cap will stay same as transaction not completed without selling

            profit = max(-prices[n] + fact(prices,dp,n+1,1,cap), 0 + fact(prices,dp,n+1,0,cap));

        }

        else{
            // We can either sell, or go to next index
            // For sell, we will turn 1 to 0, so that from now on we want to buy
            // Also for sell, Cap will decrease by 1, and not sell, cap will remain same as transaction not completed without selling

            profit = max(prices[n] + fact(prices,dp,n+1,0,cap-1), 0 + fact(prices,dp,n+1,1,cap));
        }


        return dp[n][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        
        // Creating a 3D dp array of [prices.sizes][2][3]
        // 2 -> buy/sell
        // 3 -> 0 or 1 or 2 transactions

        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2, vector<int>(3, -1)));

        // Initially we starting from 0th index and want to buy, so 0
        // And no transaction done, so cap is 2

        return fact(prices,dp, 0,0,2);

    }
};