class Solution {
public:
    bool isPalindrome(string s)
    {
        int n = s.length();
        for(int i=0;i<n/2;i++)
            if(s[i]!=s[n-1-i])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> m;
        set<pair<int,int>>result;
        vector<vector<int>> final;
        int n = words.size();
        for(int i=0;i<n;i++)
            m[words[i]]=i;
        for(int i=0;i<n;i++)
        {
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            int len = rev.length();
            for(int j=0;j<=len;j++)
            {
                if(isPalindrome(words[i]+rev.substr(len-j,j)) && m.find(rev.substr(len-j,j))!=m.end() && i!=m[rev.substr(len-j,j)])
                    result.insert(pair<int,int>{i,m[rev.substr(len-j,j)]});
                if(isPalindrome(rev.substr(0,j)+words[i]) && m.find(rev.substr(0,j))!=m.end() && i!=m[rev.substr(0,j)])
                    result.insert(pair<int,int>{m[rev.substr(0,j)],i});
            }
        }
        for(auto r:result)
        {
            vector<int> v;
            v.push_back(r.first);
            v.push_back(r.second);
            final.push_back(v);
        }
        return final;
    }
};

