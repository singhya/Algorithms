class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<long int> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]=0;
            for(int j=0;j<words[i].length();j++)
                v[i] |= 1<<(words[i][j]-'a');
        }
        int max = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if((v[i]&v[j])==0 && words[i].length()*words[j].length()>max)
                    max = words[i].length()*words[j].length();
        return max;

    }
};
