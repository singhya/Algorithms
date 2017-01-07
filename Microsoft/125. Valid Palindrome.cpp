class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        for(int i=0;i<s.size();i++)
            s[i] = tolower(s[i]);
        while(start<=end)
        {
            while(start<s.size() && !(tolower(s[start])>='a' && s[start]<='z' || s[start]>='0' && s[start]<='9'))
                start++;
            while(end>=0 && !(s[end]>='a' && s[end]<='z' || s[end]>='0' && s[end]<='9'))
                end--;
            if(start==s.size() || end<0)
                return true;
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
