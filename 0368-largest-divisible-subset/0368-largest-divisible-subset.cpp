class Solution {
public:
    int tabulation(vector<int>& nums, vector<int>& index) {
        int n = nums.size();

        // Every element itself is an LDS of length 1
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0
                && dp[i] < dp[j] + 1) {

                    dp[i] = dp[j] + 1;
                    // Store previous index
                    index[i] = j;
                }
            }
        }

        // Find the index where the longest LDS ends
        int m = 0;
        int lastindex = 0;

        for (int i = 0; i < n; i++) {
            if (m < dp[i]) {
                m = dp[i];
                lastindex = i;
            }
        }

        return lastindex;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        // IMPORTANT, sort the nums array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // index[i] stores the previous index of i
        vector<int> index(n);

        // Initially, every element points to itself
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        int lastindex = tabulation(nums, index);

        vector<int> ans;

        ans.push_back(nums[lastindex]);

        // Follow the previous indices
        while (index[lastindex] != lastindex) {
            lastindex = index[lastindex];

            ans.push_back(nums[lastindex]);
        }


        return ans;
    }
};