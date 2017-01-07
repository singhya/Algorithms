class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int  m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    if(i-1>=0 && board[i-1][j]=='X') continue;
                    if(j-1>=0 && board[i][j-1]=='X') continue;
                    if(board[i][j]=='.') continue;
                    count++;
                }
        return count;

    }
};
