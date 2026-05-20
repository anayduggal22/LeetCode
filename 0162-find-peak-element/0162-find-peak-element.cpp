class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        // Only 1 number is present
        if (nums.size() == 1) {
            return 0;
        }
        // First Number is Peak
        if (nums[0] > nums[1]) {
            return 0;
        }
        // Last Number is Peak
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }

        int low = 1;                // Second
        int high = nums.size() - 2; // Second Last

        while(low <= high){

            int mid = (low + high) / 2;

            if (nums[mid] > nums[mid - 1] 
            && nums[mid] > nums[mid + 1]) {

                return mid; // Index of the peak element
            }

            // If mid is on the left of peak, then it should be
            // Greater than its previous and Smaller than its next

            else if(nums[mid] > nums[mid - 1]){
                low = mid + 1; // Peak is on the right
            }

            // If mid is on the right of peak, then it should be
            // Smaller than its previous and Greater than its next

            else{
                high = mid - 1; // Peak is on the left
            }
        }

        return -1;
    }
};