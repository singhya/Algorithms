class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> result;
        if(n==0)
            return result;
        vector<pair<int,int>>opt(n);
        opt[0].first=1;
        opt[0].second = -1;
        int max = INT_MIN;
        int head=0;
        for(int i=1;i<n;i++)
        {
            opt[i].first = 1;
            opt[i].second = -1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&& opt[j].first+1>opt[i].first)
                {
                    opt[i].first = opt[j].first+1;
                    opt[i].second = j;
                }
            }
            if(max<opt[i].first)
            {
                head = i;
                max = opt[i].first;
            }
        }
        while(head!=-1)
        {
            result.push_back(nums[head]);
            head = opt[head].second;
        }
        return result;
    }
};
