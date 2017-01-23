class Solution {
public:
    vector<int> KMP(string s){
        int n = s.size();
        vector<int> result(n,0);
        int index = 0;
        for(int i=1; i<n; i++){
            if(s[i] == s[index]){
                result[i] = result[i-1]+1;
                index++;
            }
            else{
                index = result[i-1];
                while(index>0 && s[i]!=s[index])
                    index = result[index-1];
                if(s[i]==s[index])
                    index++;
                result[i] = index;
            }
        }
        return result;
    }
    string shortestPalindrome(string s) {
       string rev = s;
       reverse(rev.begin(),rev.end());
       string new_string = s + "#" + rev;
       vector<int> table = KMP(new_string);
       string to_add = s.substr(table[table.size()-1]);
       reverse(to_add.begin(), to_add.end());
       return to_add+s;
    }
};
