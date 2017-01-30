class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), opt_max = nums[0], opt_min = nums[0], max = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int temp = opt_max;
                opt_max = std::max(opt_min*nums[i], nums[i]);
                opt_min = std::min(temp*nums[i], nums[i]);
            }
            else{
                opt_max = std::max(opt_max*nums[i], nums[i]);
                opt_min = std::min(opt_min*nums[i], nums[i]);
            }
            max = std::max(opt_max, max);
        }
        return max;
    }
};
