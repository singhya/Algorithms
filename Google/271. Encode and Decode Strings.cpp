class Codec {
public:
    void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";
        for(auto s:strs)
        {
            for(auto c:s)
                res+=to_string((int)c)+";";
            res+="|";
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        split(s,'|',res);
        for(int i=0;i<res.size();i++)
        {
            string result_element;
            vector<string> p;
            split(res[i],';',p);
            for(auto str:p)
                result_element+=(char)(stoi(str));
            res[i] = result_element;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
