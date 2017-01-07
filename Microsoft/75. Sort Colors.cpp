class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>count(3,0);
        for(auto n:nums)
            count[n]++;
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            while(count[c]==0)
                c++;
            nums[i] = c;
            count[c]--;
        }
    }
};
