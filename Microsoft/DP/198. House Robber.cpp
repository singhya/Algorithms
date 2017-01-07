class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int>opt(n,0);
        opt[0] = nums[0];
        if(n==1)
            return opt[0];
        opt[1] = max(opt[0],nums[1]);
        for(int i=2;i<n;i++){
            opt[i] = max(opt[i-2]+nums[i],opt[i-1]);
        }
        return opt[n-1];
    }
};
