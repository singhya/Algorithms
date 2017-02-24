class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26,0), res(10,0), n = {0,2,6,8,3,7,5,4,1,9};
        for(int i=0; i<s.size(); i++)
            count[s[i]-'a']++;
        string result, determiners = "zwxghsvfon";
        vector<string> nums = {"zero", "two", "six", "eight", "three", "seven", "five", "four", "one", "nine"};
        for(int i=0;i<10;i++)
            if(count[determiners[i]-'a']>0)
                while(count[determiners[i]-'a']>0){
                    res[n[i]]++;
                    for(int j=0;j<nums[i].size();j++) count[nums[i][j]-'a']--;
                }
        for(int i=0;i<10;i++)
            while(res[i]-->0)
                result+=to_string(i);
        return result;
    }
};
