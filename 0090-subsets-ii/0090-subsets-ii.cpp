class Solution {
public:
    void combinations(int index, vector<int>& nums, set<vector<int>>& s,
                      vector<int>& ds) {

        if (index == nums.size()) {
            s.insert(ds);
            return;
        }

        ds.push_back(nums[index]);
        combinations(index + 1, nums, s, ds);

        ds.pop_back();
        combinations(index + 1, nums, s, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // IMPORTANT
        sort(nums.begin(), nums.end());

        set<vector<int>> s;
        vector<int> ds;
        int index = 0;

        combinations(index, nums, s, ds);

        vector<vector<int>> ans;

        for(auto i : s){
            ans.push_back(i);
        }

        return ans;
    }
};