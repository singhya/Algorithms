class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int back = 0;
        vector<string> result(0);
        if(nums.size()==0)
            return result;
        if(nums.size()==1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int fwd = 1;
        while(fwd<nums.size())
        {
            if(nums[fwd]==nums[fwd-1]+1)
            {
                fwd++;
                continue;
            }
            else
            {
                if(fwd-2>=back && nums[fwd-1]==nums[fwd-2]+1)
                    result.push_back(to_string(nums[back])+"->"+to_string(nums[fwd-1]));
                else
                    result.push_back(to_string(nums[fwd-1]));
                back = fwd;
                fwd = fwd+1;
            }
        }
        if(back<nums.size())
        {
            //1,2,3
            if(back<fwd-1)
                result.push_back(to_string(nums[back])+"->"+to_string(nums[fwd-1]));
            //1,3,4
            else
                result.push_back(to_string(nums[back]));
        }
        return result;
    }
};
