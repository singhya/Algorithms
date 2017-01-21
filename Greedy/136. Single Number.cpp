class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0;
        for(auto num:nums) number = number^num;
        return number;
    }
};
