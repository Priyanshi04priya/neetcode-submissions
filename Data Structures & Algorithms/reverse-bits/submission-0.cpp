class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int i=0;
        int t=32;
        while(t--){
            if((n>>i)&1)res=res|(1<<(31-i));
            i++;
        }
        return res;
    }
};
