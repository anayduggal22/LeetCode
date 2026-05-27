class Solution {
public:
    int count(vector<int>& nums, int wieght) {

        int c = 1; // No. of splits
        int last = nums[0]; // First element

        for (int i = 1; i < nums.size(); i++) {
            if (last + nums[i] <= wieght) {
                last += nums[i];
            } else {
                c++;
                last = nums[i];
            }
        }

        return c;
    }

    int splitArray(vector<int>& nums, int k) {

        int m = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            m = max(m, nums[i]);
            sum += nums[i];
        }

        int low = m; // Minimum can be the max element in the array so that to accomodate every element
        int high = sum; // Worst case when we have to split only 1

        int ans = 0;

        while (low <= high) {

            int mid = (low + high) / 2;

            int c = count(nums, mid);

            if (c <= k) {
                ans = mid;
                high = mid - 1;
            } 
            // When the given wieght produced splits which are greater than k, then we will increase the wieght
            else {
                low = mid + 1;
            }
        }

        return ans; // The min weight which will give k splits
    }
};