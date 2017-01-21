class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int back = 0, front = 0;
        while(front<nums.size()){
            if(nums[front]!=0)
                nums[back++] = nums[front];
            front++;
        }
        while(back<nums.size()) nums[back++] = 0;
    }
};
