class Solution {
public:

    int fact(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){

        // Base Case
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int m = INT_MAX;

        for(int k = i ; k <= j; k++){

            int cost = (cuts[j+1] - cuts[i-1]) + 
            fact(i,k-1,cuts,dp) + fact(k+1,j,cuts, dp);

            m = min(m,cost);
        }


        return dp[i][j] = m;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

        // IMPORTANT
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

        // i, j, cuts, dp
        return fact(1,c,cuts,dp);
    }
};