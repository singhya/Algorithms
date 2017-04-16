class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = s.size()-1;
        int j = g.size()-1;
        int count = 0;
        while(i>=0 && j>=0){
            if(s[i]>=g[j]){
                i--;
                j--;
                count++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};