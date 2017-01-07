class Solution {
public:
    void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }
    int lengthLongestPath(string input) {
        vector<string> lines;
        int max = 0;
        split(input,'\n',lines);
        map<int,int> path_length;
        path_length[-1] = 0;
        for(auto l:lines)
        {
            vector<string>words;
            split(l,'\t',words);
            int level = words.size()-1;
            if(words[level].find('.')!=std::string::npos)
            {
                int length = path_length[level-1]+words[level].length();
                max = std::max(max,length);
            }
            else
            {
                path_length[level] = path_length[level-1]+words[level].length()+1;
            }
        }
        return max;
    }
};
