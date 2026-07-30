class Solution {
public:
    int fact(int n, vector<vector<int>>& dp, int s1, vector<int>& nums) {

        if (n == 0) {
            if (nums[0] == 0 && s1 == 0) {
                return 2; // {0} & {}
            } else if (s1 == 0 || s1 == nums[0]) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[n][s1] != -1) {
            return dp[n][s1];
        }

        int nottake = 0 + fact(n - 1, dp, s1, nums);
        int take = 0;

        if (nums[n] <= s1) {
            take = fact(n - 1, dp, s1 - nums[n], nums);
        }

        return dp[n][s1] = take + nottake;
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

        if(abs(target) > sum){
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