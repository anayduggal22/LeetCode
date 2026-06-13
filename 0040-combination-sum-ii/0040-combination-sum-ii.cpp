class Solution {
public:
    void combinations(int index, vector<int>& candidates,
                      vector<vector<int>>& ans, vector<int>& ds, int sum,
                      int target) {

        if (sum == target) {
            ans.push_back(ds);
            return;
        } else if (sum > target) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i - 1] == candidates[i]) {
                continue;
            }

            ds.push_back(candidates[i]);
            sum += candidates[i];
            combinations(i + 1, candidates, ans, ds, sum, target);

            ds.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // IMPORTANT
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        int index = 0;

        combinations(index, candidates, ans, ds, sum, target);

        return ans;
    }
};