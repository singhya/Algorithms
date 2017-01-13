class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 2, j = 2;
        if(n<=2) return n;
        while(j<n){
            while(j<n && nums[j]==nums[i-1] && nums[j]==nums[i-2]) j++;
            if(j<n) nums[i++] = nums[j++];
        }
        return i;
    }
};
