class Solution {
public:
    int fact(int n, vector<int>& nums, vector<int>& arr) {

        if (n == 0) {
            return nums[0];
        }

        if (arr[n] != -1) {
            return arr[n];
        }

        // Either pick this index and go to prev of prev
        int pick = nums[n];
        if (n - 2 >= 0) {
            pick += fact(n - 2, nums, arr); // n-2 cos not adjacent
        }

        // Or not pick this index and go to prev;
        int notpick = 0 + fact(n - 1, nums, arr);

        return arr[n] = max(pick, notpick); // IMPORTANT
    }

    int rob(vector<int>& nums) {

        vector<int> arr(nums.size(), -1);

        return fact(nums.size() - 1, nums, arr);
    }
};