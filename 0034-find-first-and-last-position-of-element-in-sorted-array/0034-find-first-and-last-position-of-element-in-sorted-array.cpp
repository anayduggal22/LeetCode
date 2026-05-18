class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        // Finding first position, i.e LOWER BOUND, nums[mid] >= x

        int first = nums.size();

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
                first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        low = 0;
        high = nums.size() - 1;

        // Finding last position, i.e UPPER BOUND - 1, nums[mid] > x
        int last = nums.size();

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] > target) {
                last = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {first, last - 1};
    }
};