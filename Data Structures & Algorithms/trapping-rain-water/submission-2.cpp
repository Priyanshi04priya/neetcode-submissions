// class Solution {
// public:
//     int trap(vector<int>& ht) {
//         int n=ht.size();
//         vector<int> lmax(n), rmax(n);
//         lmax[0]=ht[0], rmax[n-1]=ht[n-1];
//         for(int i=1;i<n;i++){
//             lmax[i]=max(ht[i],lmax[i-1]);
//         }
//         for(int j=n-2;j>=0;j--){
//             rmax[j]=max(ht[j], rmax[j+1]);
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans+=min(lmax[i],rmax[i])-ht[i];
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& ht) {
//         int n=ht.size();
//         vector<int> lmax(n), rmax(n);
//         lmax[0]=ht[0], rmax[n-1]=ht[n-1];
//         for(int j=n-2;j>=0;j--){
//             rmax[j]=max(ht[j], rmax[j+1]);
//         }

//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(i>0)lmax[i]=max(ht[i],lmax[i-1]);
//             ans+=min(lmax[i],rmax[i])-ht[i];
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int trap(vector<int>& ht) {
        //Two pointer approach---> SC-O(1) and TC-O(N)
        int n=ht.size();
        int l=0, h=n-1;
        int ans=0;
        int lmax=0, rmax=0;
        while(l<h){
            lmax=max(lmax,ht[l]);
            rmax=max(rmax,ht[h]);
            if(lmax<rmax){
                ans+=lmax-ht[l];
                l++;
            }
            else {
                ans+=rmax-ht[h];
                h--;
            }
        }

        return ans;
    }
};

