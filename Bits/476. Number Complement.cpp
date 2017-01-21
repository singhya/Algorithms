class Solution {
public:
    int findComplement(int num) {
        int mask = ~0, res = ~num;
        while(num){
            num=num>>1;
            mask = mask<<1;
        }
        return res^mask;
    }
};
