class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> m;
        for(int i=0;i<nums.size();i++)
            m.insert(pair<int,int>{nums[i],i});
        vector<int> result;
        for(auto i:nums)
            if(m.find(target-i)!=m.end())
            {
                if(i!=target-i)
                {
                    result.push_back(m.equal_range(i).first->second);
                    result.push_back(m.equal_range(target-i).first->second);
                    return result;
                }
                else if(m.count(i)>1)
                {
                    auto it = m.equal_range(i).first;
                    result.push_back(it->second);
                    it++;
                    result.push_back(it->second);
                    return result;
                }
            }
        return result;
    }
};
