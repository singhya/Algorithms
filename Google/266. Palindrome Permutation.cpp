class Solution {
public:

    bool canPermutePalindrome(string s) {
        int len = s.length();
        vector<int> count(256,0);
        int odds = 0;
        for(int i=0;i<len;i++)
            count[s[i]]++;
        for(int i=0;i<count.size();i++)
            if(count[i]%2!=0)
                odds++;
        if(odds>1)
            return false;
        return true;
    }
};
