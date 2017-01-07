class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int result = 0;
        for(int i=30;i>=0;i--){
            mask = mask | (1<<i);
            unordered_set<int>selected;
            for(auto n:nums)
                selected.insert( (n & mask) );
            int cand = result | (1<<i);
            for(int j=0;j<nums.size();j++){
                if(selected.find(cand ^ (nums[j]&mask))!=selected.end()){
                    result = cand;
                    break;
                }
            }
        }
        return result;
    }
};
