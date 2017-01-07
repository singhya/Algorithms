class Solution {
public:
    void split(string s, char delim, vector<int>&res)
    {
        stringstream str(s);
        string elem;
        while(getline(str,elem,delim)){
            res.push_back(stoi(elem));
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        split(version1,'.',v1);
        split(version2,'.',v2);
        int i = 0;
        while(i<v1.size()&&i<v2.size())
            if(v1[i]>v2[i])
                return 1;
            else if(v1[i]<v2[i])
                return -1;
            else
                i++;
        while(i<v1.size())
            if(v1[i++]!=0)
                return 1;
        while(i<v2.size())
            if(v2[i++]!=0)
                return -1;
        return 0;
    }
};
