class Solution {
public:

    int fact(vector<int>& prices, vector<vector<int>>& dp, int index, int buy){

        // Base Case
        if(index == prices.size()){
            // Out of bound so return 0;

            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        // For buying, we will subtract that price
        // For selling, we will add that price

        if(buy == 0){
            // Two cases to buy the stock at this index or go to next index without buying stock
            // So after buying we will make buy = 1, because we want to sell it now
            // And for going to next index, buy will be same

            profit = max(-prices[index] + fact(prices,dp,index+1,1)
            , 0 + fact(prices,dp,index +1, 0));
        }

        else if(buy == 1){
            // Two cases to sell the stock at this index or go to next index without selling stock
            // So for selling this we will make buy = 0, because we want to buy a new stock
            // And for going to next index, buy will be same

            profit = max(prices[index] + fact(prices,dp,index+1,0)
            , 0 + fact(prices,dp,index +1, 1));
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size() + 1,vector<int>(2,-1));
        // [prices.size()][2(buy OR sell)]
        // Buy = 0
        // Sell = 1

        // Initially we want to buy a stock
        return fact(prices, dp, 0, 0);
    }
};