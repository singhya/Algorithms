class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return;
        int i=n;
        int min = nums[n-1];
        while(i-2>=0)
        {
            if(nums[i-2]<nums[i-1])
                break;
            i--;
        }
        int index = i-2;
        if(index>=0)
        {
            int next_bigger_index = index+1;
            for(int j=index+2;j<n;j++)
            {
                if(nums[j]>nums[index] && nums[j]<=nums[next_bigger_index])
                    next_bigger_index = j;
            }
            swap(nums[index],nums[next_bigger_index]);
        }
        reverse(nums.begin() + index+1,nums.end());
    }
};
