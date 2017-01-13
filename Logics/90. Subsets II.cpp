class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        result.push_back(vector<int>(0));
        int i=0;
        while(i<nums.size()){
            int j;
            for(j=i+1;j<nums.size() && nums[j]==nums[i];j++);
            int count = j-i;
            int n = result.size();
            for(int k=0;k<n;k++){
                vector<int> v = result[k];
                for(int l=0;l<count;l++){
                    v.push_back(nums[i]);
                    result.push_back(v);
                }
            }
            i = j;
        }
        return result;
    }
};
