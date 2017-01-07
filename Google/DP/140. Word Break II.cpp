class Solution {
public:
    vector<string> DFS(string s, unordered_set<string>& wordDict, unordered_map<string,vector<string>>&m)
    {
        vector<string> res;
        if(m.find(s)!=m.end())
            return m[s];
        for(auto i:wordDict)
        {
            if(s.find(i)==0)
            {
                vector<string> result = DFS(s.substr(i.length()),wordDict,m);
                if(s.length()==i.length())
                {
                    res.push_back(i);
                }
                if(result.size()>0)
                {
                    for(auto j:result)
                        res.push_back(i+" "+j);
                }
            }
        }
        m[s]=res;
        return res;
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<string,vector<string>>m;
        return DFS(s,wordDict,m);
    }
};
