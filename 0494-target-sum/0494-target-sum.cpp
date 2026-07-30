class Solution {
public:
    int fact(int n, vector<vector<int>>& dp, int s1, vector<int>& nums) {

        for (int i = 0; i <= s1; i++) {
            if (nums[0] == 0 & i == 0) {
                dp[0][i] = 2;
            } else if (i == 0 || i == nums[0]) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {

                int nottake = dp[i - 1][j];
                int take = 0;

                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = take + nottake;
            }
        }

        return dp[n][s1];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // This question boils down to finding the number
        // two subsets from nums covering all the elements
        // And whose difference is equal to target

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];
        }
        // s1 + s2 = sum
        // s1 - s2 = target
        // s1 = (sum + target)/2

        if (abs(target) > sum) {
            return 0;
        }

        if ((sum + target) % 2 != 0) {
            return 0;
        }

        int s1 = (sum + target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(s1 + 1, -1));
        int n = nums.size() - 1;

        return fact(n, dp, s1, nums);
    }
};