class Solution {
public:

    int fact(vector<int>& coins, int amount, int n, vector<vector<int>>& dp){
        //Base Case

        for(int w = 0; w <= amount; w++){
            
            if(w % coins[0] == 0){
                dp[0][w] = w / coins[0];
            }
            else{
                dp[0][w] = 1e9;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amount; j++){

                int nottake = 0 + dp[i-1][j];

                int take = INT_MAX;

                if(coins[i] <= j){
                    take = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(nottake,take);
            }
        }

        return dp[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));

        int n = coins.size() - 1;

        int ans = fact(coins, amount, n, dp);

        if(ans >= 1e9){
            return -1; // Amount cannot be made up
        }

        return ans;

    }
};