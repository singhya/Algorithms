class Solution {
public:
    void reverseWords(string &s) {

        for(int i=0;i<s.size();)
             if(s[i]==' ' && (i-1<0 || s[i-1]==' '))
                 s.erase(s.begin()+i);
             else
                 i++;
        if(s[s.size()-1]==' ')
            s.erase(s.begin()+s.size()-1);
        reverse(s.begin(),s.end());
        int i = 0;
        int j = 1;
        while(j<s.size())
        {
            if(s[j]==' ')
            {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
                j=i+1;
            }
            else
                j++;
        }
        reverse(s.begin()+i,s.end());
    }
};
