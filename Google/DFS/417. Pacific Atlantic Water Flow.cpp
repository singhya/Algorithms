class Solution {
public:
    void DFS(int i, int j, vector<vector<bool>>&ocean, vector<vector<int>>&matrix, int m, int n, int prev){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j]<prev || ocean[i][j]){
            return;
        }
        ocean[i][j] = true;
        DFS(i+1,j,ocean,matrix,m,n,matrix[i][j]);
        DFS(i,j+1,ocean,matrix,m,n,matrix[i][j]);
        DFS(i-1,j,ocean,matrix,m,n,matrix[i][j]);
        DFS(i,j-1,ocean,matrix,m,n,matrix[i][j]);
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<pair<int,int>> result;
        if(m==0)
            return result;
        int n = matrix[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n, false));
        vector<vector<bool>> atlantic(m,vector<bool>(n, false));
        for(int i=0;i<n;i++){
            DFS(0,i,pacific,matrix,m,n,0);
            DFS(m-1,i,atlantic,matrix,m,n,0);
        }
        for(int i=0;i<m;i++){
            DFS(i,0,pacific,matrix,m,n,0);
            DFS(i,n-1,atlantic,matrix,m,n,0);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back(pair<int,int>(i,j));
                }
            }
        }
        return result;
    }
};
