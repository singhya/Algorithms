class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&visited)
    {
        if(visited[i][j]>0)
            return visited[i][j];
        else
        {
            int m = matrix.size();
            int n = matrix[0].size();
            int max = 1;
            if(i-1>=0 && matrix[i-1][j]>matrix[i][j]) max=std::max(max,dfs(matrix,i-1,j,visited)+1);
            if(j-1>=0 && matrix[i][j-1]>matrix[i][j]) max=std::max(max,dfs(matrix,i,j-1,visited)+1);
            if(i+1<m && matrix[i+1][j]>matrix[i][j]) max=std::max(max,dfs(matrix,i+1,j,visited)+1);
            if(j+1<n && matrix[i][j+1]>matrix[i][j]) max=std::max(max,dfs(matrix,i,j+1,visited)+1);
            visited[i][j] = max;
        }
        return visited[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n;
        if(m>0)
            n = matrix[0].size();
        else
            return 0;
        int max = 0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int smaller = 0;
                if(i-1>=0 && matrix[i-1][j]<matrix[i][j]) smaller++;
                if(j-1>=0 && matrix[i][j-1]<matrix[i][j]) smaller++;
                if(i+1<m && matrix[i+1][j]<matrix[i][j]) smaller++;
                if(j+1<n && matrix[i][j+1]<matrix[i][j]) smaller++;
                if(smaller>0)
                    continue;
                max=std::max(max,dfs(matrix,i,j,visited));
            }
        return max;
    }
};
