class Solution {
public:
    string shortestPalindrome(string s) {
       int j=0;
       int len=s.length();
       for(int i=len-1;i>=0;i--)
           if(s[i]==s[j])j++;
       if(j==len)
           return s;
       string last = s.substr(j);
       string rev = last;
       reverse(rev.begin(),rev.end());
       return rev+shortestPalindrome(s.substr(0,j))+last;
    }
};
