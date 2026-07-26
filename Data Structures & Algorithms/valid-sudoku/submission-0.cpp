class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]={false};
        bool col[9][9]={false};
        bool box[9][9]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                //board index is from 0-8 
                //'1'-'1'=0    '2'-'1'=1 in int
                int num=board[i][j]-'1';
                int boxind=(i/3)*3+(j/3);
                if(rows[i][num] || col[j][num] || box[boxind][num])return false;
                rows[i][num]=true;
                col[j][num]=true;
                box[boxind][num]=true;
            }
        }
        return true;
    }
};
