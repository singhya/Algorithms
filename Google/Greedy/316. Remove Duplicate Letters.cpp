class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length()==0)
            return "";
        vector<int>count(26,0);
        for(int i=0;i<s.length();i++)
            count[s[i]-'a']++;
        int pos = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<s[pos]) pos = i;
            if(--count[s[i]-'a']==0) break;
        }
        int index = s.find(string(1,s[pos]),pos+1);
        while(index!=-1)
        {
            s.replace(index,1,"");
            index = s.find(string(1,s[pos]),index);
        }
        return s[pos]+removeDuplicateLetters(s.substr(pos+1));
    }
};
