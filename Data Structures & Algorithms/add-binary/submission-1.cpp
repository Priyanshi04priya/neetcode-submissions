class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;
        string res="";
        
        while(i>=0 && j>=0){
            int d1=a[i]-'0';
            int d2=b[j]-'0';
            int ans= carry^d1^d2;
            res+= ans+'0';
            carry=(d1 & d2)|(carry & (d1 ^ d2));
            i--, j--;
        }
        while(i>=0){
            int d=a[i]-'0';
            res+=(d^carry)+'0';
            carry = d&carry;
            i--;
        }
        while(j>=0){
            int d=b[j]-'0';
            res+=(d^carry)+'0';
            carry = d&carry;
            j--;
        }
        if(carry)res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
};