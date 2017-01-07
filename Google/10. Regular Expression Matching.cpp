class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector< vector<bool >>M(m+1,vector<bool>(n+1,false));
        M[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            M[i][0]=false;
        }
        for(int j=1;j<=n;j++)
        {
            if(p[j-1]=='*' && M[0][j-2])
                M[0][j]=true;
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]!='*')
                {
                    if(M[i-1][j-1] && (p[j-1]==s[i-1] || p[j-1]=='.'))
                    {
                        M[i][j]=true;
                    }
                }
                else
                {
                    if(M[i][j-2] || (M[i-1][j] && (p[j-2]==s[i-1] || p[j-2]=='.')))
                            M[i][j]=true;
                }
            }

        return M[m][n];
    }
};
