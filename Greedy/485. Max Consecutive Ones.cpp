class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, res = 0;
        for(int i=0;i<nums.size();i++){
            count = nums[i]==1? count + 1 : 0;
            res = max(count,res);
        }
        return res;
    }
};
