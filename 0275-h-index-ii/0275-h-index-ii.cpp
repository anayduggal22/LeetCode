class Solution {
public:
    int hIndex(vector<int>& citations) {

        int low = 0;
        int high = citations.size() - 1;
        int ans = 0;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (citations[mid] >= citations.size() - mid) {
                ans = citations.size() - mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};