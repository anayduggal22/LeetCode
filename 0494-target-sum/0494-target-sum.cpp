class Solution {
public:
    int fact(int n, int s1, vector<int>& nums) {

        vector<int> prev(s1 + 1, -1);

        for (int i = 0; i <= s1; i++) {
            if (nums[0] == 0 & i == 0) {
                prev[i] = 2;
            } else if (i == 0 || i == nums[0]) {
                prev[i] = 1;
            } else {
                prev[i] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {

            vector<int> curr(s1 + 1, -1);

            for (int j = 0; j <= s1; j++) {

                int nottake = prev[j];
                int take = 0;

                if (nums[i] <= j) {
                    take = prev[j - nums[i]];
                }

                curr[j] = take + nottake;
            }

            prev = curr;
        }

        return prev[s1];
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

        int n = nums.size() - 1;

        return fact(n, s1, nums);
    }
};