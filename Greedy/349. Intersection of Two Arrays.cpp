class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> vec;
        for(auto num: nums1) s.insert(num);
        for(auto num: nums2)
            if(s.find(num)!=s.end()){
                vec.push_back(num);
                s.erase(num);
            }
        return vec;
    }
};
