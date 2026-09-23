class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        // IMPORTANT
        // Initialize with 0 to compensate for base case
        // dp should be 1 more size as in for loop we are going
        // 1 more

        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, 0));

        // We will do opposite of Recursive Method
        // i => 1 to n => now n to 1
        // j => n to 1 => now 1 to n

        for (int i = nums.size() - 2; i >= 1; i--) {
            for (int j = 1; j <= nums.size() -2 ; j++) {

                // Base Case
                if (i > j) {
                    continue;
                }

                int m = INT_MIN;

                for (int k = i; k <= j; k++) {

                    int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                               dp[i][k - 1] + dp[k + 1][j];

                    m = max(m, cost);
                }

                dp[i][j] = m;
            }
        }

        // dp[i][j]
        return dp[1][nums.size() - 2];
    }
};