class Solution {
public:
    vector<string> getStr(string w, int len, int index)
    {
        vector<string>s;
        int n = w.length();
        if(index>=n)
            return s;
        for(int i=index;i<=w.length()-len;i++)
        {
            string new_word = w.substr(0,i)+to_string(len)+w.substr(i+len);
            vector<string>new_words;
            for(int j=1;j<=new_word.length();j++)
            {
                new_words = getStr(new_word,j,i+to_string(len).size()+1);
                s.insert(s.end(),new_words.begin(),new_words.end());
            }
            s.push_back(new_word);
        }
        return s;
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        result.push_back(word);
        for(int i=1;i<=word.length();i++)
        {
            vector<string> res = getStr(word,i,0);
            result.insert(result.end(),res.begin(),res.end());
        }
        return result;
    }
};
