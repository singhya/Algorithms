class Solution {
public:
    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
    bool isValidSerialization(string preorder) {
        stack<string>s;
        vector<string>str;
        split(preorder,',',str);
        int n = str.size();
        int diff = 1;
        for(int i=0;i<n;i++)
        {
            diff--;
            if(diff<0)
                return false;
            if(str[i]!="#")
            diff+=2;
        }
        if(diff==0)
            return true;
        return false;
    }
};
