class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c;
        if (r>0)
            c = board[0].size();
        else
            return;
        vector<vector<int>> result(r,vector<int>(c,0));
        vector<int>v(c,0);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int sum=0;
                for(int k=max(0,i-1);k<min(r,i+2);k++)
                    for(int l=max(0,j-1);l<min(c,j+2);l++)
                        sum+=board[k][l]&1;
                if(sum==3)
                    board[i][j]=board[i][j]|2;
                if(sum==4&&board[i][j]==1)
                    board[i][j]=board[i][j]|2;
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                board[i][j]=board[i][j]>>1;
            }
        }
    }
};
