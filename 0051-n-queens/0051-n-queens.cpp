class Solution {
public:

    bool valid(vector<string>& board, int row, int col){
        
        int r = row;
        int c = col;

        // There can be 3 cases when queen placed is not valid:-

        // 1.When there is a queen just behind
        while(col > 0){
            if(board[row][--col] == 'Q'){
                return false;
            }
        }

        // 2.When there is a queen on the upper behind diagonal
        row = r;
        col = c;

        while(col > 0 && row > 0){
            if(board[--row][--col] == 'Q'){
                return false;
            }
        }

        // 3.When there is a queen on the lower behind diagonal
        row = r;
        col = c;

        while(col > 0 && row < board.size() - 1){
            if(board[++row][--col] == 'Q'){
                return false;
            }
        }


        // Else it is valid
        return true;
    }

    void solve(vector<vector<string>>& ans,vector<string>& board, int index){

        // Base Case
        if(index == board.size()){
            ans.push_back(board);
            return;
        }

        
        for(int i = 0 ; i < board.size() ;i++){

            if(valid(board,i, index) == true){
                board[i][index] = 'Q';

                solve(ans,board,index+1);

                // BackTracking and Removing Queen for next possible
                board[i][index] = '.';
            }
        }


    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n,'.');

        for(int i = 0 ; i < n ; i++){
            board[i] = s;
        }


        int index = 0;

        solve(ans,board,index);

        return ans;
    }
};