class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i=size-1;i>=0;i--)
        {
            digits[i]++;
            if(digits[i]>9)
                digits[i]=0;
            else
                break;
        }
    }
};