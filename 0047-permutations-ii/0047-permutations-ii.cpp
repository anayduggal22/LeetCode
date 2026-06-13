class Solution {
public:
    void combination(vector<int>& nums, set<vector<int>>& s, int index) {

        if (index == nums.size()) {
            s.insert(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);
            combination(nums, s, index + 1); // Going to next position
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        int index = 0;

        combination(nums, s, index);

        vector<vector<int>> ans;

        for (auto i : s) {
            ans.push_back(i);
        }

        return ans;
    }
};