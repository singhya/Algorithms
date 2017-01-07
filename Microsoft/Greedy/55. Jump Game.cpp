class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        int canReach = 0;
        while(index<nums.size() && canReach>=index)
        {
            canReach = max(index+nums[index],canReach);
            index++;
        }
        return (index==nums.size())? true : false;
    }
};
