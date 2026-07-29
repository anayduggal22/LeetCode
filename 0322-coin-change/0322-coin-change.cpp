class Solution {
public:

    int fact(vector<int>& coins, int amount, int n){
        
        vector<int>prev(amount + 1, -1);
        
        //Base Case
        for(int w = 0; w <= amount; w++){
            
            if(w % coins[0] == 0){
                prev[w] = w / coins[0];
            }
            else{
                prev[w] = 1e9;
            }
        }

        for(int i = 1; i <= n; i++){

            vector<int>curr(amount + 1, -1);

            for(int j = 0; j <= amount; j++){

                int nottake = 0 + prev[j];

                int take = INT_MAX;

                if(coins[i] <= j){
                    take = 1 + curr[j-coins[i]];
                }

                curr[j] = min(nottake,take);
            }

            prev = curr;

        }

        return prev[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size() - 1;

        int ans = fact(coins, amount, n);

        if(ans >= 1e9){
            return -1; // Amount cannot be made up
        }

        return ans;

    }
};