class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = (low + high)/2;

            if(nums[mid] == target){
                return true;
            }

            // Else find the sorted part of the array from mid

            // But before that there could be a case when comparing 
            // mid with low and high, all of them have same value
            // To Prevent that, just decrement high and increment low

            if(nums[mid] == nums[high] && nums[mid] == nums[low]){

                low++;
                high--;
                continue;
            }

            else if(nums[mid] >= nums[low]){

                if(target <= nums[mid] && target >= nums[low]){

                    high = mid - 1;
                }

                else {
                    low = mid + 1;
                }
            }

            else if(nums[mid] <= nums[high]){

                if(target >= nums[mid] && target <= nums[high]){

                    low = mid + 1;
                }

                else {
                    high = mid - 1;
                }
            }
        }

        return false;
        
    }
};