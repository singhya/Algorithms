class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        vector<int> opt(end-start+1,0);
        opt[0] = nums[start];
        opt[1] = max(nums[start],nums[start+1]);
        for(int i = start+2,j=2;i<=end;i++,j++)
            opt[j] = max(opt[j-1],opt[j-2]+nums[i]);
        return opt[end-start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        else if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};
