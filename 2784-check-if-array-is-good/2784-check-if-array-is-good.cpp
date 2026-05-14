class Solution {
public:
    bool isGood(vector<int>& nums) {
        int m = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++){
            m = max(m,nums[i]);
        }

        if(m + 1 != nums.size()){
            return false;
        }
        
        sort(nums.begin(), nums.end());

        if(nums[nums.size() -1] != nums[nums.size() - 2]){
            return false;
        }

        for(int i = 0 ; i < nums.size() - 1; i++){
            if(nums[i] != i+1){
                return false;
            }
        }

        return true;
    }
};