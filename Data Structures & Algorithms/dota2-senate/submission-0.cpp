class Solution {
public:
    void update(char c,vector<bool>& b,string &senate, int index){
        int n=senate.size();
        int i=(index+1)%n;
        while(true){
            if(!b[i] && senate[i]==c){
                b[i]=true;
                return;
            }
            i=(i+1)%n;
        }
    }
    string predictPartyVictory(string senate) {
        int cntr=0, cntd=0;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R')cntr++;
            else cntd++;
        }
        vector<bool> blocked(n,false);
        int i=0;
        while(cntr>0 && cntd>0){
            if(!blocked[i]){
                //opposition ki position find krke block kr do
                if(senate[i]=='R'){
                    update('D',blocked,senate,i);
                    cntd--;
                }
                else{
                    update('R',blocked,senate,i);
                    cntr--;
                }
            }
            i=(i+1)%n;
        }
        return cntr>0?"Radiant":"Dire";
    }
};