class Solution {
public:
    bool check(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pos = i + 1;
                break;
            }
        }
        for (int i = pos; i < pos + nums.size() - 1; i++) {
            if (nums[i % nums.size()] > nums[(i + 1) % nums.size()]) {
                return false;
            }
        }
        return true;
    }
};