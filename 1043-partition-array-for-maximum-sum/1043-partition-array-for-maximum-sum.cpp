class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        // Size + 1, because loop will go till arr.size()
        vector<int> dp(arr.size() + 1, 0);

        // Base Case
        dp[arr.size()] = 0;

        // In Memoization, i-> 0 to n-1
        // So Tabulation, i-> n-1 to 0

        for (int i = arr.size() - 1 ; i >= 0; i--) {

            int ans = INT_MIN;

            int m = INT_MIN;

            int l = 0;

            for (int j = i; j < min((i + k), int(arr.size())); j++) {

                l++;

                m = max(m, arr[j]);

                // sum is lenght*maxelement in that subarray +
                // finding partition sum from rest of the subbarry
                int sum = l * m + dp[j + 1];

                ans = max(ans, sum);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};