class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        helper(num,target,result,"",0,0,0);
        return result;
    }
    void helper(string num, int target, vector<string>&res, string path, int pos, long eval, long multiplication)
    {
        int n = num.length();
        if(eval==target && pos==n)
        {
            res.push_back(path);
            return;
        }
        for(int i=pos;i<n;i++)
        {
            if(i!=pos && num[pos]=='0')
                break;
            string str = num.substr(pos,i-pos+1);
            long number = stol(str);
            if(path=="")
            {
                helper(num,target,res,str,i+1,number,number);
            }
            else
            {
                helper(num,target,res,path + "+" + str,i+1,eval+number,number);
                helper(num,target,res,path + "-" + str,i+1,eval-number,-number);
                helper(num,target,res,path + "*" + str,i+1,eval-multiplication+multiplication*number,multiplication*number);
            }
        }
    }

};
