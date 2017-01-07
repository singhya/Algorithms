class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int max = 0;
        for(auto it=s.begin();it!=s.end();it++)
        {
            if(s.find(*it-1)==s.end())
            {
                int next = *it+1;
                int count=1;
                while(s.find(next)!=s.end())
                {
                    count++;
                    next++;
                }
                max = std::max(count,max);
            }
        }
        return max;
    }
};
