class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string,vector<string>>m;
        for(int i=0;i<strings.size();i++)
        {
            string s = "";
            for(int j=0;j<strings[i].size();j++)
            {    int value = strings[i][j]-strings[i][0];
                if(value<0)
                    value +=26;
                s+=(char)(value+'a');
            }
            if(m.find(s)==m.end())
            {
                vector<string> v;
                v.push_back(strings[i]);
                m[s]=v;
            }
            else
                m[s].push_back(strings[i]);

        }
        vector<vector<string>>result;
        for(auto i:m)
        {
            result.push_back(i.second);
        }
        return result;
    }
};
