class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>opt(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
            opt[i][i]=0;
        for(int len=2;len<=n;len++)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                int min = INT_MAX;
                for(int j=i;j<=i+len-1;j++)
                {
                    int left;
                    if(j-1<i)
                        left = 0;
                    else
                        left = opt[i][j-1];
                    int right;
                    if(i+len-1<j+1)
                        right = 0;
                    else
                        right = opt[j+1][i+len-1];
                    int to_add = std::max(left,right);
                    min = std::min(min,j+to_add);
                }
                opt[i][i+len-1] = min;
            }
        }
        return opt[1][n];
    }
};
