class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0, twenty=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5)five++;
            if(bills[i]==10){
                ten++;
                if(five<=0)return false;
                else five--;
            }
            else if(bills[i]==20){
                twenty++;
                if(five>=3)five-=3;
                else if(ten>=1 && five>=1){
                    ten--;
                    five--;
                }
                else return false;
            }
        }
        return true;
    }
};