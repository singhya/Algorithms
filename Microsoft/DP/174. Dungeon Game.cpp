class cell{
    public:
    int current_energy;
    int min_energy;
    cell(int e)
    {
        current_energy = e;
    }
};
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>opt(m,vector<int>(n));
        opt[m-1][n-1]=max(1-(dungeon[m-1][n-1]),1);
        for(int i=m-2;i>=0;i--)
            opt[i][n-1] = max(opt[i+1][n-1]-dungeon[i][n-1],1);
        for(int i=n-2;i>=0;i--)
            opt[m-1][i] = max(opt[m-1][i+1]-dungeon[m-1][i],1);
        for(int i=m-2;i>=0;i--)
            for(int j=n-2;j>=0;j--)
                opt[i][j] = max(1,min(opt[i+1][j]-dungeon[i][j],opt[i][j+1]-dungeon[i][j]));
        return opt[0][0];
    }
};
