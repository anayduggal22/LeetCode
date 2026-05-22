class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int m = -1;
        for (int i = 0; i < nums.size(); i++) {
            m = max(m, nums[i]);
        }

        int low = 1;
        int high = m; // Largets Number in the Array

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int sum = 0;

            for (int i = 0; i < nums.size(); i++) {
                sum += ceil((double)nums[i] / mid);
            }

            if (sum <= threshold) {
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