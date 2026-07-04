// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         //******************Line sweep technique, in which we sweep a line(|) at at any point line violates the condition ....take action***********
//         map<int,int> mpp;  //{point, + or -} if passengers get on - + else -
//         int maxi=0;
//         for(auto it:trips){
//             mpp[it[1]]+=it[0];
//             mpp[it[2]]+=-it[0];
//             maxi=max(maxi,it[2]);
//         }

//         int line=0;
//         for(auto it:mpp){
//             line+=it.second;
//             if(line>capacity)return false;
//         }
//         return true;
//     }
// };


//The Difference Array technique is used when you have many range updates and want to avoid updating every element in the range.
//Instead of updating every element in a range, Only mark where the effect starts and where it ends. Later, take the prefix sum to reconstruct the final array.

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //******************Difference array tech., ***********
        vector<int> diff(1001,0);
        int maxi=0;
        for(auto it:trips){
            diff[it[1]]+=it[0];
            diff[it[2]]+=-it[0];
            maxi=max(maxi,it[2]);
        }

        int line=0;
        for(auto it:diff){
            line+=it;
            if(line>capacity)return false;
        }
        return true;
    }
};