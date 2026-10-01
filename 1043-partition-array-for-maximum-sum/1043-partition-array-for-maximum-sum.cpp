class Solution {
public:

    int fact(int i, int k, vector<int>& arr, vector<int>& dp){

        // Base Case
        if(i >= arr.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // Traversing from index till index + k of till array size
        // if index + k > array size

        int ans = INT_MIN;

        int m = INT_MIN;

        int l = 0;

        for(int j = i; j < min((i+k), int(arr.size())) ; j++){

            l++;

            m = max(m, arr[j]);

            // sum is lenght*maxelement in that subarray + 
            // finding partition sum from rest of the subbarry
            int sum = l*m + fact(j+1,k,arr,dp);

            ans = max(ans,sum);

        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

      vector<int> dp(arr.size(), -1);

      return fact(0,k,arr,dp);  
    }
};