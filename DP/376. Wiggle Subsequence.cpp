class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        vector<int> IncreasingDP(n);
        vector<int> DecreasingDP(n);
        int max = 1;
        IncreasingDP[0] = 1;
        DecreasingDP[0] = 1;
        for(int i=1; i<nums.size(); i++){
            int increasingMax = 0, decreasingMax = 0;
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]){
                    increasingMax = std::max(DecreasingDP[j],increasingMax);
                }
                if(nums[i]<nums[j]){
                    decreasingMax = std::max(IncreasingDP[j],decreasingMax);
                }
            }
            IncreasingDP[i] = increasingMax+1;
            DecreasingDP[i] = decreasingMax+1;
            max = std::max(max,IncreasingDP[i]);
            max = std::max(max,DecreasingDP[i]);
        }
        return max;
    }
};
