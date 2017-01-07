class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        if(nums.size()==1)
        {
            vector<int> v;
            v.push_back(nums[0]);
            res.push_back(v);
            return res;
        }
        for(int i=0;i<nums.size();i++)
        {
            vector<int> new_vector(nums.begin(),nums.begin()+i);
            new_vector.insert(new_vector.end(),nums.begin()+i+1,nums.end());
            vector<vector<int>> results = permute(new_vector);
            for(auto v:results)
            {
                v.insert(v.begin(),nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};
