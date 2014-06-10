class Solution {
public:
    void record(vector<vector<short> > &v, int i, int j, int c) {
        int t=i/3, s=j/3;
        v[0][i]|=(1<<(c-1));
        v[1][j]|=(1<<(c-1));
        v[2][3*t+s]|=(1<<(c-1));
    }
    void clear(vector<vector<short> >&v, int i, int j, int c) {
        int t=i/3, s=j/3;
        short mask=(1<<(c-1));
        v[0][i]^=mask;
        v[1][j]^=mask;
        v[2][3*t+s]^=mask;
    }
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<short> > rec(3,vector<short>(9,0));
        for(int i=0;i<9;++i) {
            for(int j=0;j<9;++j) {
                if(board[i][j]!='.') {
                    int c=board[i][j]-'0';
                    record(rec,i,j,c);
                }
            }
        }
        dfs(0,0,rec,board);
    }
    vector<int> avail(int i, int j, vector<vector<short> > &c) {
        vector<int> r;
        int t=i/3, s=j/3;
        short tmp=~(c[0][i]|c[1][j]|c[2][t*3+s]);
        if(tmp==0) return r;
        for(int k=0;k<9;++k) {
            if(tmp&1) r.push_back(k+1);
            tmp=tmp>>1;
        }
        return r;
    }
    bool dfs(int i, int j, vector<vector<short> > &rec, vector<vector<char> > &b) {
        if(i==8 && j==8) {
            if(b[i][j]!='.') {
                return true;
            } else {
                auto av=avail(i,j,rec);
                if(av.empty()) return false;
                else {
                    b[i][j]=av[0]+'0';
                    return true;
                }
            }
        } else {
            if(b[i][j]=='.') {
                auto av=avail(i,j,rec);
                if(av.empty()) return false;
                else {
                    for(auto e:av) {
                        record(rec, i, j, e);
                        b[i][j]=e+'0';
                        if(dfs((j==8)?(i+1):i, (j+1)%9, rec, b)) return true;
                        clear(rec, i, j, e);
                        b[i][j]='.';
                    }
                }
            } else return dfs((j==8)?(i+1):i, (j+1)%9, rec, b);
        }
        return false;
    }
};
