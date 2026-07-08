class Solution {
public:
    int getSum(int a, int b) {
        int carry=0;
        int ans=0;
        for (int pos=0;pos<32;pos++) {
            int bita=(a>>pos)&1;
            int bitb=(b>>pos)&1;
            int sum=bita^bitb^carry;
            ans |= (sum << pos);
            carry = (bita & bitb) | (bita & carry) | (bitb & carry);
        }
        return ans;
    }
};
