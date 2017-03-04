class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int back = 0, temp;
        while(back<nums.size() && nums[back]!=val)
            back++;
        temp = back+1;
        while(temp<nums.size()){
            while(temp<nums.size() && nums[temp]==val) temp++;
            if(temp<nums.size()) nums[back++] = nums[temp++];
        }
        return back;
    }
};
