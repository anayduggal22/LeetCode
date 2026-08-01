class Solution {
public:

    int fact(int n, int amount, vector<vector<int>>& dp, vector<int>& coins){

        if(n == 0){
            if(amount % coins[0] == 0){
                return 1; // We can use it m times to get to amount
            }
            else{
                return 0;
            }

        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        int nottake = fact(n-1, amount, dp, coins);

        int take = 0;

        if(coins[n] <= amount){
            // There is a chance we can use this coin again, so n is not reduced
            take =  fact(n, amount - coins[n], dp, coins);
        }

        return dp[n][amount] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));

        int n = coins.size() -1;

        return fact(n,amount,dp,coins);
    }
};