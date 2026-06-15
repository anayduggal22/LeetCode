class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& board, int index, vector<int>& rowmap, vector<int>& upperdiagonalmap, vector<int>& lowerdiagonalmap) {

        // Base Case
        if (index == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < board.size() ;i++){

            if(rowmap[i] == 0 &&
               lowerdiagonalmap[i + index] == 0 &&
               upperdiagonalmap[(board.size() - 1) + (i-index)] == 0){
                rowmap[i] = 1;
                lowerdiagonalmap[i + index] = 1;
                upperdiagonalmap[(board.size() - 1) + (i-index)] = 1;
                board[i][index] = 'Q';

                solve(ans,board,index+1, rowmap, upperdiagonalmap, lowerdiagonalmap);

                // BackTracking and Removing Queen for next possible
                rowmap[i] = 0;
                lowerdiagonalmap[i + index] = 0;
                upperdiagonalmap[(board.size() - 1) + (i-index)] = 0;
                board[i][index] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Map to check if placed queen is valid or not
        vector<int> rowmap(n, 0);
        vector<int> upperdiagonalmap(2*n - 1, 0);
        vector<int> lowerdiagonalmap(2*n - 1, 0);

        vector<string> board(n);

        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        int index = 0;

        solve(ans, board, index, rowmap, upperdiagonalmap, lowerdiagonalmap);

        return ans;
    }
};