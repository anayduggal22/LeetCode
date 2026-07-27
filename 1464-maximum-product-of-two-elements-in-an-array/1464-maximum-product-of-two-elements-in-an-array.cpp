class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 2) {
            return (nums[0] - 1) * (nums[1] - 1);
        }

        sort(nums.begin(), nums.end());

        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    }
};