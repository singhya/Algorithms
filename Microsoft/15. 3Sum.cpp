class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i-1>=0 && nums[i]==nums[i-1])
                continue;
            int k = n-1;
            for(int j=i+1;j<k;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                    continue;
                while(nums[i]+nums[j]+nums[k]>0 && k>j+1)
                    k--;
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int>v = {nums[i],nums[j],nums[k]};
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};
