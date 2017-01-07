class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==0)
            return result;
        else if(nums.size()==1)
        {
            vector<int> v;
            v.push_back(nums[0]);
            result.push_back(v);
            return result;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i-1>=0 && nums[i]==nums[i-1])
                continue;
            vector<int> new_vector(nums.begin(),nums.begin()+i);
            new_vector.insert(new_vector.end(),nums.begin()+i+1, nums.end());
            vector<vector<int>> res = helper(new_vector);
            for(auto v:res)
            {
                v.insert(v.begin(),nums[i]);
                result.push_back(v);
            }
        }
        return result;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return helper(nums);
    }
};
