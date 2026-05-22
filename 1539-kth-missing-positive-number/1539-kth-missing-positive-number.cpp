class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) {
            return k;
        }

        int low = 0;
        int high = arr.size() - 1;

        // First finding the range of the missing number

        while (low <= high) {

            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1); // The No. that should be at that place if it was not missing

            if(missing < k){
                low = mid + 1; // Missing elements range on right side
            }
            else{
                high = mid - 1;
            }
        }

        return low + k;
    }
};