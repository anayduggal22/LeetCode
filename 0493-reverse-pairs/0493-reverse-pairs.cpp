class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, int& count) {

        // First Counting the pairs
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }

        // Then Merging them in sorted order
        int left = low;
        int right = mid + 1;

        vector<int> temp;
        int k = 0;

        while (left <= mid && right <= high) {

            if (nums[left] < nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }

            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[i + low] = temp[i];
        }
    }

    void mergesort(vector<int>& nums, int low, int high, int& count) {

        if (low < high) {
            int mid = (high + low) / 2;

            mergesort(nums, low, mid, count);
            mergesort(nums, mid + 1, high, count);

            merge(nums, low, mid, high, count);
        }
    }

    int reversePairs(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int count = 0;

        mergesort(nums, low, high, count);

        return count;
    }
};