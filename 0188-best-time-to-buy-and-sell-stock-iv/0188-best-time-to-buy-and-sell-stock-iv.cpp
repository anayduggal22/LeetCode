class Solution {
public:

    int maxProfit(int k,vector<int>& prices) {
        
        // Creating a 3D dp array of [prices.sizes][2][3]
        // 2 -> buy/sell
        // k+1 -> 0 to k transactions

        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(k+1, -1)));

        // Base Cases

        // 1. When n == prices.size()
        int n = prices.size();

        for(int buy = 0; buy <= 1 ;buy++){
            for (int cap = 0; cap <= k; cap++){
                dp[n][buy][cap] = 0;
            }
        }

        // 2. When cap = 0;
        int cap = 0;

        for(int n = 0; n <prices.size() ;n++){
            for (int buy = 0; buy <= 1; buy++){
                dp[n][buy][cap] = 0;
            }
        }


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

                        profit = max(-prices[n] + dp[n+1][1][cap], 0 + dp[n+1][0][cap]);

                    }

                    else{
                        // We can either sell, or go to next index
                        // For sell, we will turn 1 to 0, so that from now on we want to buy
                        // Also for sell, Cap will decrease by 1, and not sell, cap will remain same as transaction not completed without selling

                        profit = max(prices[n] + dp[n+1][0][cap-1], 0 + dp[n+1][1][cap]);
                    }

                    dp[n][buy][cap] = profit;

                }
            }
        }

        return dp[0][0][k];
        
    }
};