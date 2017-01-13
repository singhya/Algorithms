class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0;
        int last = n-1;
        while(first<=last){
            int mid = (first+last)>>1;
            if(target==nums[mid]) return mid;
            else if(target>nums[mid]) first = mid+1;
            else last = mid-1;
        }
        return first;
    }
};
