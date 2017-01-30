class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(256, 0);
        for(auto c:magazine)
            count[c]++;
        for(auto c:ransomNote)
            if(count[c]==0) return false;
            else count[c]--;
        return true;
    }
};
