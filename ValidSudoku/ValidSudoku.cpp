class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> rec(9);
        //vector<int> rec2(9,0);
        for(int i=0;i<9;i++) {
            fill_n(rec.begin(),9,0);
            for(int j=0;j<9;j++) {
                int tmp=myParse(board[i][j]);
                if(tmp!=-1) {
                    if(rec[tmp]==1) return false;
                    rec[tmp]++;
                }
            }
            fill_n(rec.begin(),9,0);
            for(int j=0;j<9;j++) {
                int tmp=myParse(board[j][i]);
                if(tmp!=-1) {
                    if(rec[tmp]==1) return false;
                    rec[tmp]++;
                }
            }
        }
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                fill_n(rec.begin(),9,0);
                for(int h=3*i;h<3*i+3;h++) {
                    for(int k=3*j;k<3*j+3;k++) {
                        int tmp=myParse(board[h][k]);
                        if(tmp!=-1) {
                            if(rec[tmp]==1) return false;
                            rec[tmp]++;
                        }
                    }
                }
            }
        }
        return true;
    }
    inline int myParse(char c) {
        if(c=='.') return -1;
        else return c-'1';
    }
};
