class Solution {
public:
    int helper(vector<int>&nums,int i, int j)
    {
        if(j==i)
            return nums[i];
        else if(i+1==j)
            return min(nums[i],nums[j]);
        else if(nums[i]<nums[j])
            return nums[i];
        int mid = (i+j)/2;
        if(nums[mid]<nums[j])
            return helper(nums,i,mid);
        else
            return helper(nums,mid,j);
    }
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
