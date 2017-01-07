struct node
{
    int x;
    int y;
    int walk;
    node(int i,int j,int z){x=i;y=j;walk=z;}
};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        vector<pair<int,int>> v;
        int buildings = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0)
                    v.push_back(pair<int,int>{i,j});
                else if(grid[i][j]==1)
                        buildings++;
        auto temp = grid;
        for(int i=0;i<v.size();i++)
        {
            queue<node>q;
            q.push(node(v[i].first,v[i].second,0));
            auto visited = grid;
            int dist = 0;
            int build = 0;
            while(!q.empty())
            {
                node new_node = q.front();
                q.pop();
                if(visited[new_node.x][new_node.y]==-1)
                    continue;
                else if(visited[new_node.x][new_node.y]==1)
                {
                    dist+=new_node.walk;
                    build++;
                    visited[new_node.x][new_node.y]=-1;
                    continue;
                }
                visited[new_node.x][new_node.y]=-1;
                if(new_node.x+1<m && grid[new_node.x+1][new_node.y]!=2 && visited[new_node.x+1][new_node.y]!=-1)
                    q.push(node(new_node.x+1,new_node.y,new_node.walk+1));
                if(new_node.x-1>=0 && grid[new_node.x-1][new_node.y]!=2 && visited[new_node.x-1][new_node.y]!=-1)
                    q.push(node(new_node.x-1,new_node.y,new_node.walk+1));
                if(new_node.y+1<n && grid[new_node.x][new_node.y+1]!=2 && visited[new_node.x][new_node.y+1]!=-1)
                    q.push(node(new_node.x,new_node.y+1,new_node.walk+1));
                if(new_node.y-1>=0 && grid[new_node.x][new_node.y-1]!=2 && visited[new_node.x][new_node.y-1]!=-1)
                    q.push(node(new_node.x,new_node.y-1,new_node.walk+1));
            }
            if(build==buildings)
                temp[v[i].first][v[i].second]=dist;
            else
                temp[v[i].first][v[i].second]=INT_MAX;
        }
        int min = INT_MAX;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0)
                    min = std::min(temp[i][j],min);
        return (min==INT_MAX)?-1:min;
    }
};
