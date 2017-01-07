class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> mat(m+1,vector<bool>(n+1,false));
        mat[0][0] = true;
        for(int i=1;i<=m;i++)
            mat[i][0] = false;
        for(int i=1;i<=n;i++)
            if(p[i-1]=='*')
                mat[0][i]=mat[0][i-1];
            else
                mat[0][i]=false;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(p[j-1]=='?')
                    mat[i][j]=mat[i-1][j-1];
                else if(p[j-1]=='*')
                    mat[i][j]=mat[i][j-1]||mat[i-1][j];
                else
                    mat[i][j]=mat[i-1][j-1]&&(s[i-1]==p[j-1]);
        return mat[m][n];

    }
};
