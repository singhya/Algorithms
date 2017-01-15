class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>> &results, vector<int>v, int cand, int index){
        v.push_back(cand);
        if(target==0)
            results.push_back(v);
        for(int i=index;i<candidates.size();i++)
            if(target>=candidates[i])
                helper(candidates, target-candidates[i], results, v,  candidates[i], i);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> v;
        for(int i=0;i<candidates.size();i++)
            if(target>=candidates[i])
                helper(candidates, target-candidates[i], results, v, candidates[i], i);
        return results;
    }
};
