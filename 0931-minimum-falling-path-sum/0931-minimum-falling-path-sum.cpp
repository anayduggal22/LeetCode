class Solution {
public:
    int fact(vector<vector<int>>& matrix) {

        vector<int>prev(matrix[0].size());
        vector<int>curr(matrix[0].size());

        for (int j = 0; j < matrix[0].size(); j++) {
            // Base Case
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size(); j++){

            int up = prev[j] + matrix[i][j];
            int leftdiag = 1e9;
            int rightdiag = 1e9;

            if(j > 0){
                leftdiag = prev[j-1] +  matrix[i][j];
            }

            if(j < matrix[0].size() - 1){
                rightdiag = prev[j+1] + matrix[i][j];
            }

            curr[j] = min(up,min(leftdiag,rightdiag));

            }

            prev = curr; // IMPORTANT
        }



        int mini = INT_MAX;

        for (int j = 0; j < matrix[0].size(); j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        return fact(matrix);
    }
};