class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
            return 1;
        for(int i=0;i<nums.size();i++)
            while(nums[i]<nums.size() && nums[i]>=0 && nums[i]!=i && nums[i]!=nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        for(int i=1; i<nums.size(); i++)
            if(i!=nums[i])
                return i;
        return nums[0]!=nums.size()?nums.size():nums.size()+1;
    }
};
