class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> opt(n+1,0);
        if(n==0)
            return 0;
        opt[0] = 1;
        if(s[0]!='0')
            opt[1] = 1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
                opt[i] = opt[i-1];
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]>='0' && s[i-1]<='6'))
                opt[i] += opt[i-2];
        }
        return opt[n];
    }
};
