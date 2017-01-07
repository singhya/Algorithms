class Solution {
public:
    string removeKdigits(string &num, int k) {
        if(num.length()==0)
            return "0";
        for(int j=0;j<num.length();j++)
            if(num[j]!='0')
            {
                num = num.substr(j);
                break;
            }
        if(k==0)
            return num;
        int i = 1;
        for(i=1;i<num.length();i++)
            if(num[i]<num[i-1])
                    break;
        num = num.substr(0,i-1)+num.substr(i);
        return removeKdigits(num,k-1);
    }
};
