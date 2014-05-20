class Solution {
public:
    vector<string> con;
    vector<vector<string> > solveNQueens(int n) {
        vector<bool> *col=new vector<bool>(n,false);
        vector<bool> *row=new vector<bool>(n,false);
        vector<bool> *dsub=new vector<bool>(2*n-1,false);
        vector<bool> *dadd=new vector<bool>(2*n-1,false);
        vector<vector<string> > *r=new vector<vector<string> >();
        solveNQueens(r,0, col,row, dsub, dadd);
        return *r;
    }
    inline string loc2String(int loc, int n) {
        string r;
        for(int i=0;i<n;i++) {
            if(i!=loc) r+=".";
            else r+="Q";
        }
        return r;
    }
    void solveNQueens(vector<vector<string> > *r, int curr, vector<bool> *col, vector<bool> *row, vector<bool> *sub, vector<bool> *add) {
        int n=col->size();
        if(curr<n) {
            for(int i=0;i<n;i++) {
                if((*col)[i] || (*sub)[n+curr-i] || (*add)[curr+i]) continue;
                else {
                    (*col)[i]=(*sub)[n+curr-i]=(*add)[curr+i]=true;
                    con.push_back(loc2String(i, n));
                    solveNQueens(r,curr+1,col,row,sub,add);
                    con.pop_back();
                    (*col)[i]=(*sub)[n+curr-i]=(*add)[curr+i]=false;
                }
            }
        } else {
            r->push_back(con);
        }
    }
};
