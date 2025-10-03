class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;        // make space for the next bit
            res |= (n & 1);   // add the last bit of n
            n >>= 1;          // drop the last bit of n
        }
        return res;
    }
};
