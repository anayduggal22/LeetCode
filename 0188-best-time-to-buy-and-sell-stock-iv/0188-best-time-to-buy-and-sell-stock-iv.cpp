class Solution {
public:

    int maxProfit(int k,vector<int>& prices) {
        
        // Creating two 2D dp array of [2][k]
        // 2 -> buy/sell
        // k+1 -> 0 to k transactions

        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        // Base Cases
        // No need as both array are assigned as 0


        for(int n = prices.size() -1; n >= 0 ; n--){
            for(int buy = 0; buy <= 1; buy++){
                // Cap starts from 1, as inside we do cap-1
                for(int cap = 1; cap <= k; cap++){

                    int profit = 0;

                    // For buy, we will subtract price
                    // For sell, we will add price

                    if(buy == 0){
                        // We can either buy, or go to next index
                        // For buy, we will turn 0 to 1, so that from now on we want to sell
                        // Cap will stay same as transaction not completed without selling

                        profit = max(-prices[n] + ahead[1][cap], 0 + ahead[0][cap]);

                    }

                    else{
                        // We can either sell, or go to next index
                        // For sell, we will turn 1 to 0, so that from now on we want to buy
                        // Also for sell, Cap will decrease by 1, and not sell, cap will remain same as transaction not completed without selling

                        profit = max(prices[n] + ahead[0][cap-1], 0 + ahead[1][cap]);
                    }

                    curr[buy][cap] = profit;

                }
            }

            ahead = curr;
        }

        return ahead[0][k];
        
    }
};