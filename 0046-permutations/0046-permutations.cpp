class Solution {
public:
    void combination(vector<int>& nums, vector<vector<int>>& ans,
                     vector<int>& ds, vector<int>& visited) {

        // Base Case
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < visited.size(); i++) {

            if (visited[i] == 0) {
                visited[i] = 1;
                ds.push_back(nums[i]);
                combination(nums, ans, ds, visited);

                visited[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        vector<int> visited(nums.size(), 0);

        combination(nums, ans, ds, visited);

        return ans;
    }
};