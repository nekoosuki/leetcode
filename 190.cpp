#include <iostream>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        int i=0;
        while(n>0){
            rev |= (n & 1) << (31 - i++);
            n >>= 1;
        }
        return rev;
    }
};
