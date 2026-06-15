class Solution {
public:

    bool valid(vector<vector<char>>& board, int row, int col, int color){

        for(int i = 0 ; i < board.size(); i++){

            // In the whole row
            if(board[row][i] == color){
                return false;
            }
            // In the whole column
            else if(board[i][col] == color){
                return false;
            }
            // In the Square
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == color){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board.size() ; j++){

                if(board[i][j] == '.'){

                    for(int color = '1'; color <= '9' ; color++){

                        if(valid(board,i,j,color) == true){
                            board[i][j] = color;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
        
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);

    }
};