class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = INT_MAX, sum = 0;
        for(int num: nums) min = std::min(min, num);
        for(auto num: nums) sum += num-min;
        return sum;
    }
};
