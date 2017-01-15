class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> DP(n,0);
        DP[0] = grid[0][0];
        for(int i=1;i<n;i++)
            DP[i] = grid[0][i]+DP[i-1];
        for(int i=1;i<m;i++){
            DP[0] = DP[0] + grid[i][0];
            for(int j=1;j<n;j++)
                DP[j] = min(DP[j-1],DP[j])+grid[i][j];
        }
        return DP[n-1];
    }
};
