class Solution {
public:
    int fact(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int m = INT_MIN;

        for (int k = i; k <= j; k++) {

            int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                       fact(i, k - 1, nums, dp) + fact(k + 1, j, nums, dp);

            m = max(m, cost);
        }

        return dp[i][j] = m;
    }

    int maxCoins(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        // fact(i,j,nums,dp)
        return fact(1, nums.size() - 2, nums, dp);
    }
};