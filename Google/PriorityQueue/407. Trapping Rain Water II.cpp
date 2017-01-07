class cell{
public:
    int row;
    int col;
    int height;
    cell(int i, int j, int h)
    {
        row = i;
        col = j;
        height = h;
    }
};
class oper{
    public:
    bool operator()(cell a, cell b) {return a.height>b.height;}
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m<2)
             return 0;
        int n = heightMap[0].size();
        if(n<2)
            return 0;
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        priority_queue<cell, vector<cell>, oper> q;
        for(int i=0;i<m;i++)
        {
            visited[i][0] = true;
            visited[i][n-1] = true;
            q.push(cell(i,0,heightMap[i][0]));
            q.push(cell(i,n-1,heightMap[i][n-1]));
        }
        for(int i=0;i<n;i++)
        {
            visited[0][i] = true;
            visited[m-1][i] = true;
            q.push(cell(0,i,heightMap[0][i]));
            q.push(cell(m-1,i,heightMap[m-1][i]));
        }
        int result = 0;
        while(!q.empty())
        {
            cell top = q.top();
            q.pop();
            vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto p:dir)
            {
                int r = top.row+p.first;
                int c = top.col+p.second;
                if(r>=0 && c>=0 && r<m &&c<n && !visited[r][c])
                {
                    result+=max(0,top.height-heightMap[r][c]);
                    visited[r][c] = true;
                    q.push(cell(r,c,max(top.height,heightMap[r][c])));
                }
            }
        }
        return result;
    }
};
