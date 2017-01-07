class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tails(n);
        int length = 0;
        for(int i=0;i<n;i++)
        {
            int start = 0;
            int last = length;
            int mid = (start+last)/2;
            while(start!=last)
            {
                if(nums[i]>tails[mid])
                    start = mid+1;
                else
                    last = mid;
                mid = (start+last)/2;
            }
            tails[last]=nums[i];
            if(last==length)
            {
                length++;
            }
        }
        return length;
    }
};
