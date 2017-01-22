class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int n = nums.size();
        for(int i=0;i<n/2;i++)
            result+=(nums[n-i-1]-nums[i]);
        return result;
    }
};
