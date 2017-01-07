class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=0;i+1<nums.size();i+=2)
        {
            if(nums[i]>nums[i+1])
            {
                swap(nums[i],nums[i+1]);
            }
            if(i+2<nums.size() && nums[i+1]<nums[i+2])
            {
                swap(nums[i+1],nums[i+2]);
            }
        }
    }
};
