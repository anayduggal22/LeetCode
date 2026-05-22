class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = -1;
        for (int i = 0; i < bloomDay.size(); i++) {
            n = max(n, bloomDay[i]);
        }

        int low = 1;
        int high = n; // Largest can be the maximum no. of days

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int count = 0;
            int b = 0;

            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] > mid) {
                    b += count / k;
                    count = 0;
                } else {
                    count++; // Count of adjacent flowers
                }
            }

            b += count / k; // IMP

            if (b >= m) { // Found More or equal than bouqets
                ans = mid;
                high = mid - 1; // Can be a more smaller than this
            }

            else {
                low = mid + 1; // Not found
            }
        }

        return ans;
    }
};