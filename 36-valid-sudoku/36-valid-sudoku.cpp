class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_map<int,int>> row;
        unordered_map<int,unordered_map<int,int>> col;
        unordered_map<int,unordered_map<int,int>> box;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                
                int boxInd = ((i/3)*3)+(j/3);
                if(row[i][board[i][j]] || col[j][board[i][j]] ||box[boxInd][board[i][j]])
                    return false;
                row[i][board[i][j]]++;
                col[j][board[i][j]]++;
                box[boxInd][board[i][j]]++;
            }
        }
        return true;
    }
};