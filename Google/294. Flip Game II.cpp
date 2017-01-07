class Solution {
public:
    bool canWin(string s) {
        int n=s.length();
        if(n<2)
            return false;
        for(int i=0;i<=n-2;i++)
        {
            if(s[i]=='+'&&s[i+1]=='+')
            {
                string new_string = s.substr(0,i)+"--"+s.substr(i+2);
                if(!canWin(new_string))
                    return true;
            }
        }
        return false;
    }
};
