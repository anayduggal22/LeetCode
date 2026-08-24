class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int aheadbuy = 0;
        int aheadsell = 0;
        int currbuy = 0;
        int currsell = 0;


        for (int i = prices.size() - 1; i >= 0; i--) {

            // Buying state
            currbuy = max(-prices[i] + aheadsell,
                           0 + aheadbuy);

            // Selling state
            currsell = max(prices[i] + aheadbuy,
                           0 + aheadsell);

            aheadbuy = currbuy;
            aheadsell = currsell;
        }

        //Returning Buy
        return aheadbuy;
    }
};