class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int counter = 32;
        while(counter--){
            result = result<<1;
            if(n&1)
                result = result^1;
            n = n>>1;
        }
        return result;
    }
};
