class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> ahead(2,0);
        vector<int> curr(2,0);

        for (int i = prices.size() - 1; i >= 0; i--) {

            // Buying state
            curr[0] = max(-prices[i] + ahead[1],
                           0 + ahead[0]);

            // Selling state
            curr[1] = max(prices[i] + ahead[0],
                           0 + ahead[1]);

            ahead = curr;
        }

        //Returning Buy
        return ahead[0];
    }
};