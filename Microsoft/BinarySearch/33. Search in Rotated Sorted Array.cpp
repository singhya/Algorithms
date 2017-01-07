class Solution {
public:
    int simpleBinarySearch(vector<int>& nums, int first, int last, int target)
    {
        //cout<<first<<" "<<last<<endl;
        while(first<=last)
        {
            int mid = (first+last)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                first = mid+1;
            else
                last = mid-1;
        }
        return -1;
    }
    int helper(vector<int>& nums, int first, int last, int target)
    {
        //cout<<first<<" "<<last<<endl;
        if(first>last)
            return -1;
        if(first==last)
            if(nums[first]==target)
                return first;
            else
                return -1;
        if(nums[first]<nums[last])
        {
            return simpleBinarySearch(nums,first,last,target);
        }
        else
        {
            int mid = (first+last)/2;
            if(nums[mid]==target)
                return mid;
            if(mid==first)
                return helper(nums, mid+1, last,target);
            if(nums[first]<nums[mid])
            {
                if(target>=nums[first] && target<=nums[mid])
                    return simpleBinarySearch(nums,first,mid,target);
                else
                    return helper(nums,mid,last,target);
            }
            else
            {
                if(target>=nums[mid] && target<=nums[last])
                    return simpleBinarySearch(nums,mid,last,target);
                else
                    return helper(nums,first,mid,target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};
