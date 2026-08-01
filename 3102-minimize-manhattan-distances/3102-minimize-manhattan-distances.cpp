class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {

        // Storing x+y and x-y along with their coordinates
        vector<pair<int, pair<int, int>>> sum;
        vector<pair<int, pair<int, int>>> diff;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            sum.push_back({x + y, {x, y}});
            diff.push_back({x - y, {x, y}});
        }

        // Sorting so that first = minimum and last = maximum
        sort(sum.begin(), sum.end());
        sort(diff.begin(), diff.end());

        // Taking the 4 extreme points
        pair<int, int> a1 = sum[sum.size() - 1].second;
        pair<int, int> a2 = sum[0].second;
        pair<int, int> b1 = diff[diff.size() - 1].second;
        pair<int, int> b2 = diff[0].second;

        vector<pair<int, int>> arr;
        arr.push_back(a1);
        arr.push_back(a2);
        arr.push_back(b1);
        arr.push_back(b2);

        int min_ans = INT_MAX;

        // Trying to remove each of the 4 candidates
        for (int i = 0; i < 4; i++) {

            pair<int, int> temp = arr[i];

            vector<int> s;
            vector<int> d;

            bool removed = false;

            // Adding all points except the one being removed
            for (int i = 0; i < points.size(); i++) {

                int x = points[i][0];
                int y = points[i][1];

                // Skip only one occurrence
                if (!removed && x == temp.first && y == temp.second) {
                    removed = true;
                    continue;
                }

                s.push_back(x + y);
                d.push_back(x - y);
            }

            // Again finding new extremes
            sort(s.begin(), s.end());
            sort(d.begin(), d.end());

            int a1 = s[s.size() - 1];
            int a2 = s[0];
            int b1 = d[d.size() - 1];
            int b2 = d[0];

            // Maximum Manhattan distance after removing this point
            int m = max(a1 - a2, b1 - b2);

            // Keeping the minimum answer
            min_ans = min(min_ans, m);
        }

        return min_ans;
    }
};