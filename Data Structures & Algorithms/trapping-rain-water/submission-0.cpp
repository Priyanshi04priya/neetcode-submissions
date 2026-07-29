class Solution {
public:
    int trap(vector<int>& ht) {
        int n=ht.size();
        vector<int> lmax(n), rmax(n);
        lmax[0]=ht[0], rmax[n-1]=ht[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(ht[i],lmax[i-1]);
        }
        for(int j=n-2;j>=0;j--){
            rmax[j]=max(ht[j], rmax[j+1]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(lmax[i],rmax[i])-ht[i];
        }
        return ans;
    }
};
