class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char> m = {{'1','1'},{'6','9'},{'8','8'},{'9','6'},{'0','0'}};
        int n = num.length();
        for(int i=0;i<=n/2;i++)
        {
            if(num[i]!=m[num[n-1-i]])
                return false;
        }
        return true;
    }
};
