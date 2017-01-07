class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto i = nums.begin();
        while(i!=nums.end())
        {
            auto next = i+1;
            while(next!=nums.end() && *next==*i)
                nums.erase(next);
            i=i+1;
        }
        return nums.size();
    }
};
