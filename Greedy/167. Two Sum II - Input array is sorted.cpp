class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int first = 0;
        int last = n-1;
        vector<int> result;
        while(first<last){
            while(numbers[first]+numbers[last]>target) last--;
            if(numbers[first]+numbers[last]==target){
                result.push_back(first+1);
                result.push_back(last+1);
                return result;
            }
            first++;
        }
        return result;
    }
};
