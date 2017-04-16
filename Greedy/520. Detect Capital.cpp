class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==0)
            return true;
        int caps = 0;
        for(int i=1;i<=word.size();i++)
            if(word[i]>='A' && word[i]<='Z')
                caps+=1;
        if(word[0]>='A' && word[0]<='Z'){
            if(caps == word.size()-1)
                return true;
            else if(caps==0)
                return true;
            else
                return false;
        }
        else{
            if(caps==0)
                return true;
            else
                return false;
        }
    }
};