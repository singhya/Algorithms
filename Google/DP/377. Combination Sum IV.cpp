class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<int> s;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        vector<int>opt(target+1,0);
        for(int i=1;i<=target;i++)
        {
            for(auto num:nums)
            {
                if(i==num)
                    opt[i]+=1;
                else if(num>i)
                    break;
                else
                    opt[i]+=opt[i-num];
            }
        }
        return opt[target];
    }
};
