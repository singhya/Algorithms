void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        split(path, '/',res);
        stack<string>s;
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()>0)
            {
                if(res[i]==".") continue;
                else if(res[i]=="..")
                {
                    if(!s.empty())
                        s.pop();
                }
                else s.push(res[i]);
            }
        }
        string result="";
        while(!s.empty())
        {
            result = "/"+s.top()+result;
            s.pop();
        }
        result = (result=="") ? "/" : result;
        return result;
    }
};
