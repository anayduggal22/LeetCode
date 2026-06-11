class Solution {
public:
    void combinations(int index, vector<int>& candidates,
                      vector<vector<int>>& ans, vector<int>& ds, 
                      int sum, int target) {

        if (index == candidates.size()) {
            if (sum == target) {
                ans.push_back(ds);
            }

            return;
        }

        if(sum < target){
            ds.push_back(candidates[index]);
            sum += candidates[index];
            combinations(index, candidates, ans, ds, sum, target);
            ds.pop_back();
            sum -= candidates[index];
        }

        combinations(index + 1, candidates, ans, ds, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        int index = 0;

        combinations(index, candidates, ans, ds, sum, target);

        return ans;
    }
};