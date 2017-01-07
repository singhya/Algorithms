class Solution {
public:
    double myPow(double x, long long int n) {
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        else if(n==-1)
            return 1/x;
        long long int pow = abs(n);
        int bit=0;
        vector<double> res = vector<double>(log2(pow)+1,0);
        res[0] = x;
        double result;
        if(pow&1)
        {
            result = x;
        }
        else
        {
            result = 1;
        }
        pow=pow>>1;
        bit++;
        while(pow)
        {
            res[bit]=res[bit-1]*res[bit-1];
            if(pow&1)
            {
                result*= res[bit];
            }
            pow=pow>>1;
            bit++;
        }
        if(n<0)
        {
            return 1.0/result;
        }
        else
            return result;
    }
};
