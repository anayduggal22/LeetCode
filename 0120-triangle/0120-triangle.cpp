class Solution {
public:
    int fact(int row, int col, vector<vector<int>>& triangle,
             vector<vector<int>>& dp) {

        vector<int>prev(col+1);

        for(int j = 0 ; j <= col ; j++){
            // Base Case, Starting from down to up
            prev[j] = triangle[row][j];
        }

        for(int i = row - 1; i >= 0 ; i--){

            vector<int>curr(col+1);

            for(int j = i; j >= 0 ; j--){

                int down = prev[j] + triangle[i][j];
                int diagonal = prev[j+1] + triangle[i][j];

                curr[j] = min(down,diagonal);
            }

            prev = curr;
        }

        return prev[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size() - 1;
        int m = triangle.size() - 1;

        vector<vector<int>> dp(
            triangle.size(),
            vector<int>(triangle[n].size(), INT_MAX)); // nxn size dp array

        return fact(n, m, triangle, dp);
    }
};