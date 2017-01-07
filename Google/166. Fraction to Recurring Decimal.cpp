class Solution {
public:
    string fractionToDecimal(long long int numerator, long long int denominator) {
        bool isNegative = false;
        if(numerator*denominator<0)
            isNegative = true;
        numerator = abs(numerator);
        denominator = abs(denominator);
        string result = isNegative?"-"+to_string(numerator/denominator):to_string(numerator/denominator);
        long long int remainder = numerator%denominator;
        if(remainder!=0)
        {
            result = result+'.';
        }
        else
        {
            return result;
        }
        unordered_map <int,int>s;
        string rhs="";
        while(s.find(remainder%denominator)==s.end() && remainder!=0)
        {
            s[remainder]=rhs.length();
            remainder = remainder*10;
            while(remainder/denominator==0)
            {
                rhs+='0';
                s[remainder] = rhs.length();
                remainder*=10;
            }
            rhs+=to_string(remainder/denominator);
            remainder = remainder%denominator;
        }
        if(remainder!=0)
        {
            int i = s[remainder%denominator];
            rhs = rhs.insert(i,"(")+")";
        }
        result+=rhs;
        return result;
    }
};
