class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        n = n-1;
        while(n>=0)
        {
            str=(char)('A'+n%26)+str;
            n = n/26-1;
        }
        return str;
    }
};
