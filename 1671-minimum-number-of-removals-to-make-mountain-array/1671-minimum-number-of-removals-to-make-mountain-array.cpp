class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        vector<int> dp1(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1) {

                    dp1[i] = dp1[j] + 1;
                }
            }
        }
        vector<int> dp2(nums.size(), 1);

        for (int i = nums.size() - 1; i >= 1; i--) {
            for (int j = i + 1; j < nums.size(); j++) {

                if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1) {

                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        int longest_bitonic = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (dp1[i] > 1 && dp2[i] > 1) {
                int m = dp1[i] + dp2[i] - 1;
                longest_bitonic = max(longest_bitonic, m);
            }
        }

        // IMPORTANT

        return nums.size() - longest_bitonic;
    }
};