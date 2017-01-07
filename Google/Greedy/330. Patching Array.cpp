class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss=1;
        int size = nums.size();
        int i=0;
        int add = 0;
        while(miss<=n)
        {
            if(i<size && nums[i]<=miss)
                miss+=nums[i++];
            else
            {
                miss+=miss;
                add++;
            }

        }
        return add;
    }
};
