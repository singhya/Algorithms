class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int sum = 1;
        for(int i=1;i<len;i++)
            sum+=pow(26,i);
        for(int i=0;i<len;i++)
            sum+=(s[i]-'A')*pow(26,len-1-i);
        return sum;
    }
};
