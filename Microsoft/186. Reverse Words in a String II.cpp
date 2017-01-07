class Solution {
public:
    void reverseWords(string &s) {
        for(int i=1;i<s.size();)
            if(s[i]==' ' && s[i-1]==' ')
                s.erase(s.begin()+i);
            else
                i++;
        int i=0;
        reverse(s.begin(),s.end());
        for(int j=1;j<s.size();j++)
            if(s[j]==' ' || s[j]=='\n')
            {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
            }
        reverse(s.begin()+i,s.end());
    }
};
