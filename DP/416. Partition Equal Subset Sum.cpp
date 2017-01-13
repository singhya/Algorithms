class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n:nums) sum+=n;
        if(sum%2!=0) return false;
        vector<bool> DP(sum/2+1,false);
        DP[0] = true;
        for(int i=0;i<nums.size();i++){
            for(int j=DP.size()-1;j>=nums[i];j--){
                DP[j] = DP[j] || DP[j-nums[i]];
            }
        }
        return DP[sum/2];
    }
};
