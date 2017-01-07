class Solution {
public:
    vector<string> rec(int n,int m)
    {
        map<string,string> ma = {{"0","0"},{"1","1"},{"6","9"},{"8","8"},{"9","6"}};
        vector<string> res;
        vector<string> final;
        if(n==0)
        {
            return final;
        }
        else if(n==1 || m==1)
        {
            vector<string> res = {"0","1","8"};
            return res;
        }
        else if(n==2)
        {
            vector<string> res = {"11","69","96","88"};
            return res;
        }
        else if(m==2)
        {
            vector<string> res = {"00","11","69","96","88"};
            return res;
        }
        else
        {
            vector<string> res = rec(n,m-2);
            for(auto &i:ma)
            {
                if(!(n==m && i.first=="0"))
                for(auto j:res)
                {
                    final.push_back(i.first+j+i.second);
                }
            }
        }
        return final;
    }
    vector<string> findStrobogrammatic(int n) {
        return rec(n,n);
    }
};
