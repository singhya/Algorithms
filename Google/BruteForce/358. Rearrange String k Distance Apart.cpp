class Solution {
public:
    string rearrangeString(string str, int k) {
        map<int,int>m;
        multimap<int,int>rev;
        int n = str.length();
        if(k==0)
            k=1;
        for(int i=0;i<n;i++)
            m[str[i]]++;
        for(auto e:m)
            rev.insert(pair<int,int>{e.second,e.first});
        int i=0;
        int start = 0;
        vector<char>res(n);
        int cycle;
        while(!rev.empty())
        {
            auto e = prev(rev.end());
            rev.erase(e);
            int count = e->first;
            int character = e->second;
            bool behind = false;
            int starting_point;
            starting_point = i;
            while(count--)
            {
                res[i]=(char)character;
                if(behind && starting_point<=i)
                    return "";
                i+=k;
                cycle+=k;
                if(i>=n)
                {
                    i=++start;
                    behind = true;
                }
            }
        }
        string result(res.begin(),res.end());
        return result;
    }
};
