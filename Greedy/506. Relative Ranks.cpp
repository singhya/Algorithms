class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> result;
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> rank;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) rank[sorted[i]] = n-i;
        for(auto num:nums)
            if(rank[num]==1) result.push_back("Gold Medal");
            else if(rank[num]==2) result.push_back("Silver Medal");
            else if(rank[num]==3) result.push_back("Bronze Medal");
            else result.push_back(to_string(rank[num]));
        return result;
    }
};
