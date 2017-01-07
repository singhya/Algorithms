class Solution {
public:
    void recursive(vector<string> &result,int left_counter, int right_counter,string s, int n)
    {
        if(s.length()==2*n)
        {
            result.push_back(s);
            return;
        }
        if(left_counter<n)
        {
            recursive(result,left_counter+1,right_counter,s+"(",n);
        }
        if(left_counter>right_counter)
        {
            recursive(result,left_counter,right_counter+1,s+")",n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recursive(result,0,0,"",n);
        return result;
    }
};
