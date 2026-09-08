class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Base Case = Direct initialize dp grid with 0

        vector<int> curr(2,0);
        vector<int> ahead1(2,0);
        vector<int> ahead2(2,0);


        //So those future states must already be calculated.So we need to go backwards

        for (int i = prices.size() - 1; i >= 0; i--) {

            // Buying state
            curr[0] = max(-prices[i] + ahead1[1],
                           0 + ahead1[0]);

            // Selling state
            curr[1] = max(prices[i] + ahead2[0],
                           0 + ahead1[1]);

            // IMPORTANT
            ahead2 = ahead1;
            ahead1 = curr;

        }

        //Returning Buy
        return ahead1[0];
    }
};