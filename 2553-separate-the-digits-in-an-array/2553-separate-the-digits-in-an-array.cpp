class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            vector<int> t ;
            while (temp > 0) {
                t.push_back(temp % 10);
                temp /= 10;
            };

            for (int j = t.size() - 1; j >= 0; j--) {

                ans.push_back(t[j]);
            }
        }

        return ans;
    }
};