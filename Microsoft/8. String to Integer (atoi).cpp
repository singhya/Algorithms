class Solution {
public:
    int myAtoi(string str) {
        int isMinus = 1;
        int i = 0;
        while(i<str.size()&&str[i]==' ')
            i++;
        if(i<str.size() && str[i]=='-')
        {
            isMinus = -1;
            i++;
        }
        else if(i<str.size() && str[i]=='+')
            i++;
        long int res=0;
        while(i<str.size())
        {
            if(!(str[i]>='0' && str[i]<='9'))
                break;
            res = res*10;
            res = res+(str[i]-'0')*(isMinus);
            if(res>=INT_MAX)
                return INT_MAX;
            if(res<=INT_MIN)
                return INT_MIN;
            i++;
        }

        return res;
    }
};
