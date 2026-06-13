class Solution {
public:
    void combinations(int index, vector<int>& candidates,
                      vector<vector<int>>& ans, vector<int>& ds, int& sum,
                      int k, int n) {
        if (ds.size() == k && sum == n) {
            ans.push_back(ds);
            return;
        } else if (ds.size() > k || sum > n || index >= candidates.size()) {
            return;
        }

        ds.push_back(candidates[index]);
        sum += candidates[index];
        combinations(index + 1, candidates, ans, ds, sum, k, n);

        ds.pop_back();
        sum -= candidates[index];
        combinations(index + 1, candidates, ans, ds, sum, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> candidates(9);

        for (int i = 0; i < 9; i++) {
            candidates[i] = i + 1;
        }

        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        int index = 0;

        combinations(index, candidates, ans, ds, sum, k, n);

        return ans;
    }
};