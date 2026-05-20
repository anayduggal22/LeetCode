class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // Only 1 number is present
        if (nums.size() == 1) {
            return nums[0];
        }
        // First Number is Single
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        // Last Number is Single
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) {
            return nums[nums.size() - 1];
        }

        int low = 1;                // Second
        int high = nums.size() - 2; // Second Last

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid - 1] 
            && nums[mid] != nums[mid + 1]) {

                return nums[mid];
            }

            // Element is not there on the left side
            // As (even, odd) are equal
            else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                     (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                low = mid + 1; // Go to right side
            }

            // Element is not there on the right side
            // As (odd, even) are equal
            else {
                high = mid - 1; // Go to left side
            }
        }

        return -1;
    }
};