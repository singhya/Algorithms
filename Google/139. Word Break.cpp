class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool > mat(n,false);
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(wordDict.find(s.substr(i,j-i+1))!=wordDict.end())
                {
                    if(i==0)
                    {
                       mat[j]=true;
                    }
                    if(i>0 && mat[i-1])
                    {
                        mat[j]=true;
                    }
                }
            }
        }
        return mat[n-1];
    }
};
