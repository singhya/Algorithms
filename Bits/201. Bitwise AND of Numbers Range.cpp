class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 1;
        while(m!=n){
            m = m>>1;
            n = n>>1;
            result = result<<1;
        }
        return result*m;
    }
};
