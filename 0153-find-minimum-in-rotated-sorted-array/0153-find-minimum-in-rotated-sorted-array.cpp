class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;

            // If the element is greater than the high element, go towards
            // right side as there are small numbers there.
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            
            // If the element is smaller than the high element, go towards
            // left side as there are greater elements there.
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
        }
        return nums[low];
    }
};
