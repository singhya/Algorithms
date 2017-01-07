class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>>q;
        int m = rooms.size();
        int n;
        if(m==0)
            return;
        else
            n = rooms[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(rooms[i][j]==0)
                    q.push(pair<int,int>{i,j});
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            if(p.first+1<m && rooms[p.first+1][p.second]==INT_MAX)
            {
                rooms[p.first+1][p.second] = rooms[p.first][p.second]+1;
                q.push(pair<int,int>{p.first+1,p.second});
            }
            if(p.second+1<n && rooms[p.first][p.second+1]==INT_MAX)
            {
                rooms[p.first][p.second+1] = rooms[p.first][p.second]+1;
                q.push(pair<int,int>{p.first,p.second+1});
            }
            if(p.first-1>=0 && rooms[p.first-1][p.second]==INT_MAX)
            {
                rooms[p.first-1][p.second] = rooms[p.first][p.second]+1;
                q.push(pair<int,int>{p.first-1,p.second});
            }
            if(p.second-1>=0 && rooms[p.first][p.second-1]==INT_MAX)
            {
                rooms[p.first][p.second-1] = rooms[p.first][p.second]+1;
                q.push(pair<int,int>{p.first,p.second-1});
            }
        }
    }
};
