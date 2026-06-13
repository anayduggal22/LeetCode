class Solution {
public:

    void combination(vector<int>& nums, vector<vector<int>>& ans, int index){

        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){

            swap(nums[index],nums[i]);
            combination(nums,ans,index+1); // Going to next position
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;

        combination(nums,ans,index);

        return ans;
    }
};