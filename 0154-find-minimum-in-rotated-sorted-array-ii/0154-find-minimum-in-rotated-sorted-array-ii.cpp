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

            // If the element is equal to the value of higher element, then 
            // we can reduce the high by value by one as it removes one of
            // duplicates and shrinks the space. And if at that time 
            // high becomes equal to low, which breaks the loop, then the 
            // MINIMUM element will be stored where mid is pointing and at 
            // the end where low is pointing too.
            else{
                high--;
            }
        }
        return nums[low];
    }
};