class Solution {
public:

    int fact(vector<int>& coins, int amount, int n, vector<vector<int>>& dp){

        if(n == 0){
            // If coins[0] can be used to get to the remaining amount then we have to use: amount/coins[0] coins to do it
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            else{
                // If it cannot, then returning a large value, which will not get accepted, or if it will, then we cannot make this amount
                return 1e9;
            }
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        int nottake = 0 + fact(coins, amount, n-1, dp);

        int take = INT_MAX;
        // Initialized with a greater value as we are finding the minimum count

        if(coins[n] <= amount){
            // We will not go to the next index, as there is a possibilty that we can use this coin again
            take = 1 + fact(coins, amount-coins[n], n, dp);
        }

    return dp[n][amount] = min(nottake,take);
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