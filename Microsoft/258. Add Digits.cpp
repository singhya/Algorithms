class Solution {
public:
    int addDigits(int num) {
        if(num!=0)
            return 1+(num-1)%9;
        else
            return 0;
    }
};
