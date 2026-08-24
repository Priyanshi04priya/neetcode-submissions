class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gp) {
        if(hand.size()%gp!=0)return false;

        map<int,int> mpp;
        for(int it:hand){
            mpp[it]++;
        }
        for(int k=0;k<hand.size()/gp;k++){
            int ele=mpp.begin()->first;
            //check can we form a grp here else false
            for(int i=ele;i<ele+gp;i++){
                if(!mpp.count(i))return false;
                mpp[i]--;
                if(mpp[i]==0)mpp.erase(i);
            }
        }
        return true;
    }
};
