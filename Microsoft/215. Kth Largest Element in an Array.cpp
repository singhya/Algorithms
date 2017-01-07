class Solution {
public:
    int quickSelect(vector<int> &nums, int first, int last, int k){
        int i = first;
        int j = last-1;
        int pivot = nums[last];
        while(i<=j)
            if(nums[i]<pivot)
                swap(nums[i],nums[j--]);
            else
                i++;
        swap(nums[i],nums[last]);
        if(i+1==k) return nums[i];
        else if(i+1<k) return quickSelect(nums, i+1, last, k);
        else return quickSelect(nums, first, i-1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }
};
