class Solution {
public:
    int modifiedIndex(int index, int len)
    {
        return (2*index+1)%(len|1);
    }
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        nth_element(nums.begin(),nums.begin()+mid,nums.end());
        int i=0;
        int left = 0;
        int right = n-1;
        int median = nums[mid];
        while(i<=right)
        {
            if(nums[modifiedIndex(i,n)]==median)
                i++;
            else if(nums[modifiedIndex(i,n)]<median)
                swap(nums[modifiedIndex(i,n)],nums[modifiedIndex(right--,n)]);
            else
                swap(nums[modifiedIndex(i++,n)],nums[modifiedIndex(left++,n)]);
        }
    }
};
