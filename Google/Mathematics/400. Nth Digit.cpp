class Solution {
public:
    int findNthDigit(int n) {
        long len = 1;
        long totalNumbers = 9;
        long counter = 1;
        while(n>totalNumbers*len)
        {
            counter+=totalNumbers;
            n = n - (totalNumbers * len++);
            totalNumbers *= 10;
        }

        counter += (n-1)/len;
        int bit = n%len;
        if(bit==0)
            bit = len;
        return (counter/(int)pow(10,len-bit))%10;
    }
};
