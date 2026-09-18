class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {

                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }

                else if (nums[i] > nums[j] && dp[i] == dp[j] + 1) {

                    dp[i] = dp[j] + 1;
                    count[i] += count[j];
                }
            }
        }

        // Finding the LIS
        int m = 0;
        for (int i = 0; i < dp.size(); i++) {
            m = max(m, dp[i]);
        }

        // Finding How many LIS
        int ans = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] == m) {
                ans += count[i];
            }
        }

        return ans;
    }
};