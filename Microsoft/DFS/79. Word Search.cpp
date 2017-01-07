class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index, int m, int n)
    {
        if(board[i][j]!=word[index])
        {
            return false;
        }
        if(board[i][j]==word[index])
        {
            char c = board[i][j];
            board[i][j]='0';
            if(index==word.size()-1)
                return true;
            if(i+1<m && dfs(board,i+1,j,word,index+1,m,n))
                return true;
            if(j+1<n && dfs(board,i,j+1,word,index+1,m,n))
                return true;
            if(i-1>=0 && dfs(board,i-1,j,word,index+1,m,n))
                return true;
            if(j-1>=0 && dfs(board,i,j-1,word,index+1,m,n))
                return true;
            board[i][j]=c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m==0)
        {
            return false;
        }
        int n = board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(dfs(board,i,j,word,0,m,n))
                {
                    return true;
                }
            }
        return false;
    }
};
