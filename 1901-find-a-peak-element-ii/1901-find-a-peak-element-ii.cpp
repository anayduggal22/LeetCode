class Solution {
public:
    void find_max(vector<vector<int>>& mat, int mid, int& index, int& m) {

        for (int i = 0; i < mat.size(); i++) {
            if (m < mat[i][mid]) {
                index = i;
                m = mat[i][mid];
            }
        }
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int low = 0;
        int high = mat[0].size() - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            int index = 0;
            int m = INT_MIN;

            find_max(mat, mid, index, m);

            int row = index;
            int col = mid;

            if (col - 1 >= 0 && 
            mat[row][col - 1] > mat[row][col]) {
                
                high = mid - 1;
            } 
            else if (col + 1 < mat[0].size() &&
            mat[row][col + 1] > mat[row][col]) {

                low = mid + 1;
            } 
            else {
                return {row, col};
            }
        }

        return {-1, -1};
    }
};