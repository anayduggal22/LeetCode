class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }

            else {
                ans.push_back({start, end});

                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};