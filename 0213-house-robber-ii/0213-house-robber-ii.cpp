class Solution {
public:
    int fact(vector<int>& arr) {

        int prev = arr[0];
        int prev2 = 0;

        for (int i = 1; i < arr.size(); i++) {

            int pick = arr[i] + prev2;
            int notpick = 0 + prev;

            prev2 = prev;
            prev = max(pick, notpick);
        }

        return prev;
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> arr1;
        vector<int> arr2;

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                arr1.push_back(nums[i]);
            }

            if (i != nums.size() - 1) {
                arr2.push_back(nums[i]);
            }
        }

        int ans1 = fact(arr1);
        int ans2 = fact(arr2);

        return max(ans1, ans2);
    }
};