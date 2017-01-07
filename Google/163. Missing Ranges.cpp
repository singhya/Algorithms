class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if(nums.size()==0)
        {
            if(lower<upper)
                result.push_back(to_string(lower)+"->"+to_string(upper));
            else
                result.push_back(to_string(lower));
            return result;
        }
        int n=nums.size();
        if(lower<nums[0])
        {
            if(lower<nums[0]-1)
            {
                result.push_back(to_string(lower)+"->"+to_string(nums[0]-1));
            }
            else
            {
                result.push_back(to_string(lower));
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1]-1)
            {
                if(nums[i]<nums[i+1]-2)
                    result.push_back(to_string(nums[i]+1)+"->"+to_string(nums[i+1]-1));
                else
                    result.push_back(to_string(nums[i]+1));
            }
        }
        if(upper>nums[n-1])
        {
            if(upper>nums[n-1]+1)
            {
                result.push_back(to_string(nums[n-1]+1)+"->"+to_string(upper));
            }
            else
            {
                result.push_back(to_string(upper));
            }
        }
        return result;
    }
};
