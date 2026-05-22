class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = -1;
        for (int i = 0; i < piles.size(); i++) {
            m = max(m, piles[i]);
        }

        int low = 1;
        int high = m;

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            long long int hours = 0;

            for (int i = 0; i < piles.size(); i++) {
                hours += ceil((double)piles[i] / mid);
            }

            if (hours <= h) {
                ans = mid;
                high = mid - 1; // Can be a more smaller than this
            }

            else {
                low = mid + 1; // Element not found
            }
        }

        return ans;
    }
};