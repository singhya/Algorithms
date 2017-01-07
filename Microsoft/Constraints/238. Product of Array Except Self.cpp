class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            res[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
