class Solution {
public:
    void traverse(int i,int j,int rows,int cols, vector<vector<char>>& grid)
    {
        if(i+1<rows && grid[i+1][j]=='1')
        {
            grid[i+1][j]='0';
            traverse(i+1,j,rows,cols,grid);
        }
        if(j+1<cols && grid[i][j+1]=='1')
        {
            grid[i][j+1]='0';
            traverse(i,j+1,rows,cols,grid);
        }
        if(i-1>=0 && grid[i-1][j]=='1')
        {
            grid[i-1][j]='0';
            traverse(i-1,j,rows,cols,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1')
        {
            grid[i][j-1]='0';
            traverse(i,j-1,rows,cols,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int rows = grid.size();
        int columns = 0;
        if(rows>0)
            columns = grid[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    grid[i][j]='0';
                    traverse(i,j,rows,columns,grid);
                }
            }
        }
        return count;
    }
};
