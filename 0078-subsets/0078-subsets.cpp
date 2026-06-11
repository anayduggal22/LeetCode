class Solution {
public:
    void combinations(int index, vector<int>& nums, vector<vector<int>>& ans,
                      vector<int>& ds) {

        if (index == nums.size()) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        combinations(index + 1, nums, ans, ds);

        ds.pop_back();
        combinations(index + 1, nums, ans, ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;

        combinations(index, nums, ans, ds);

        return ans;
    }
};