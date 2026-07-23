class Solution {
public:
    void merge(vector<int>& v, int l, int m, int r){
        int i=l,j=m+1;
        vector<int> temp;
        while(i<=m && j<=r){
            if(v[i]<=v[j]){
                temp.push_back(v[i]);
                i++;
            }
            else{
                temp.push_back(v[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(v[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(v[j]);
            j++;
        }

        for(int i=l;i<=r;i++){
            v[i]=temp[i-l];
        }
    }

    void partition(vector<int> &v,int left,int right){
        if(left>=right)return ;
        int m=left+(right-left)/2;
        partition(v,left,m);
        partition(v,m+1,right);
        merge(v,left,m,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        partition(nums,0,nums.size()-1);
        return nums;
    }
};