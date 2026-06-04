class Solution {
public:
    bool canJump(vector<int>& nums) {

        int reaching_index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > reaching_index) {
                return false;
            }

            reaching_index = max(reaching_index, i + nums[i]);
        }

        return true;
    }
};