class Solution {
public:
    void combination(vector<int>& nums, vector<vector<int>>& ans,
                     vector<int>& ds, int index) {

        ans.push_back(ds);

        for (int i = index; i < nums.size(); i++) {

            if (i != index && nums[i - 1] == nums[i]) {
                continue;
            }

            ds.push_back(nums[i]);
            combination(nums, ans, ds, i + 1);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;

        combination(nums, ans, ds, index);

        return ans;
    }
};