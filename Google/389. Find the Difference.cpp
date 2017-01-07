class Solution {
public:
    char findTheDifference(string s, string t) {
        long int sum = 0;
        for(int i=0;i<t.length();i++)
            sum+=t[i];
        for(int i=0;i<s.length();i++)
           sum-=s[i];
        return (char)(sum);
    }
};
