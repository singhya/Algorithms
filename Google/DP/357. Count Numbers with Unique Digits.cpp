class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        int total = 9;
        int number_of_digits = 9;
        int result=10;
        n=min(n-1,9);
        while(n-- )
        {
            total*=number_of_digits;
            result+=total;
            number_of_digits--;
        }
        return result;
    }
};
