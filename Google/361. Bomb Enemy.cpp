class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        vector<int>cols(n);
        int rowCount;
        int max = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0 || grid[i][j-1]=='W')
                {
                    rowCount = 0;
                    for(int k=j;k<n && grid[i][k]!='W';k++)
                    {
                        if(grid[i][k]=='E')
                        rowCount++;
                    }
                }
                if(i==0 ||grid[i-1][j]=='W')
                {
                    cols[j]=0;
                    for(int k=i;k<m && grid[k][j]!='W';k++)
                    {
                        if(grid[k][j]=='E')
                        cols[j]++;
                    }
                }
                if(grid[i][j]=='0')
                    max = std::max(rowCount+cols[j],max);
            }
        }
        return max;
    }
};
