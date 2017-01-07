class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0)
            return "";
        vector<vector<bool>>opt(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            opt[i][i] = true;
        string res = s.substr(0,1);
        int max = 1;
        for(int len=2;len<=n;len++)
            for(int i=0;i<=n-len;i++)
            {
                if(s[i]==s[len+i-1] && (i+1>len+i-2 || opt[i+1][len+i-2]))
                {
                    opt[i][len+i-1] = true;
                    if(len>max)
                    {
                        res = s.substr(i,len);
                        max = len;
                    }
                }
            }
        return res;
    }
};
