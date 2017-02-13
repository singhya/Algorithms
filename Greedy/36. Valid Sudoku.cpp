class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0;i<n;i++){
            vector<bool> row(10,false);
            for(int j=0;j<n;j++){
                if(board[i][j]>='1' && board[i][j]<='9')
                    if(row[board[i][j]-'0'])
                        return false;
                    else
                        row[board[i][j]-'0'] = true;
            }
            vector<bool> col(10,false);
            for(int j=0;j<n;j++){
                if(board[j][i]>='0' && board[j][i]<='9')
                    if(col[board[j][i]-'0'])
                        return false;
                    else
                        col[board[j][i]-'0'] = true;
            }
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                vector<bool> box(10,false);
                for(int k=0;k<n;k++)
                    if(board[k/3+i*3][k%3+j*3]>='1' && board[k/3+i*3][k%3+j*3]<='9')
                        if(box[board[k/3+i*3][k%3+j*3]-'0'])
                            return false;
                        else
                            box[board[k/3+i*3][k%3+j*3]-'0'] = true;
            }
        return true;
    }
};
