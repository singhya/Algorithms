class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>(0));
        for(int i=0;i<nums.size();i++){
            int n = result.size();
            for(int j=0;j<n;j++){
                vector<int> v = result[j];
                v.push_back(nums[i]);
                result.push_back(v);
            }
        }
        return result;
    }
};
