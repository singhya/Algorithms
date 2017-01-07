class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = "";
        for(int i=0;i<sentence.size();i++)
            s+=sentence[i]+" ";
        int n = s.size();
        int start = 0;
        int count = 0;
        for(int j=0;j<rows;j++){
            int last = start+cols-1;
            while(s[last%n]!=' ' && s[(last+1)%n]!=' ' && last>0)
                last--;
            if(s[(last+1)%n]==' ')
                last++;
            count += (last+1)/n;
            start = (last+1)%n;
        }
        return count;
    }
};
