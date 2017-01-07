class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<string>> m={{'1',vector<string>()},{'2',vector<string>{"a","b","c"}},{'3',vector<string>{"d","e","f"}},{'4',vector<string>{"g","h","i"}},{'5',vector<string>{"j","k","l"}},{'6',vector<string>{"m","n","o"}},{'7',vector<string>{"p","q","r","s"}},{'8',vector<string>{"t","u","v"}},{'9',vector<string>{"w","x","y","z"}},{'*',vector<string>{"+"}},{'0',vector<string>{" "}},{'#',vector<string>{"h","X"}}};
        vector<string> final_result;
        if(digits.length()==0)
        {
            return final_result;
        }
        else if(digits.length()==1)
        {
            return m[digits[0]];
        }
        else
        {
            if(digits[0]=='0')
                return final_result;
            vector<string> result = m[digits[0]];
            for(int i=0;i<result.size();i++)
            {
                vector<string> res = letterCombinations(digits.substr(1));
                if(res.size()==0)
                    return final_result;
                for(int j=0;j<res.size();j++)
                    final_result.push_back(result[i]+res[j]);
            }
        }
        return final_result;
    }
};
