class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int sum = 1;
        for(int i=1; i<nums.size();i++){
            if(num!=nums[i])
                sum--;
            else
                sum++;
            if(sum<0){
                num = nums[i];
                sum++;
            }
        }
        return num;
    }
};
