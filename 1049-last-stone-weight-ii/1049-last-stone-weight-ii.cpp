class Solution {
public:

    bool fact(vector<int>& stones, vector<vector<int>>& dp, int n, int target){

        // Store the result in the dp
        if(target == 0){
            return dp[n][target] = true;
        }

        // Store the result in the dp
        if(n == 0){
            return dp[n][target] = (stones[0] == target);
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        bool nottake = fact(stones, dp, n-1, target);

        bool take = false;

        if(target >= stones[n]){
            take = fact(stones, dp, n-1, target - stones[n]);
        }

        return dp[n][target] = (take || nottake);
    }

    int lastStoneWeightII(vector<int>& stones) {

        int sum = 0;
        for(int x : stones) sum += x;

        vector<vector<int>> dp(stones.size(),
                               vector<int>(sum + 1, -1));

        int n = stones.size() - 1;

        // IMPORTANT, check for all values
        for(int i = 0; i <= sum; i++){
            fact(stones, dp, n, i);
        }

        int m = INT_MAX;

        // ONLY 1 HALF NEEDED AS THE SECOND IS JUST A COPY
        for(int i = 0; i <= sum / 2; i++){

            if(dp[n][i]){

                m = min(m, sum - 2 * i);
            }
        }

        return m;
    }
};