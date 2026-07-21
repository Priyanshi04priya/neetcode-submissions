class Solution {
public:
    int maxArea(vector<int>& ht) {
        int n=ht.size();
        int lt=0, rt=n-1;
        int maxi=0;
        while(lt<=rt){
            maxi=max(min(ht[lt],ht[rt])*(rt-lt), maxi);
            if(ht[lt]<=ht[rt]){
                lt++;
            }
            else rt--;
        }
        return maxi;
    }
};