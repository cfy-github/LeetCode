class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> *col=new vector<bool>(n,false);
        vector<bool> *row=new vector<bool>(n,false);
        vector<bool> *dsub=new vector<bool>(2*n-1,false);
        vector<bool> *dadd=new vector<bool>(2*n-1,false);
        return totalNQueens(0, col,row, dsub, dadd);
    }
    int totalNQueens(int curr, vector<bool> *col,vector<bool> *row,vector<bool> *sub, vector<bool> *add) {
        int n=col->size();
        int sum=0;
        if(curr<n) {
            for(int i=0;i<n;i++) {
                if((*col)[i] || (*sub)[n+curr-i] || (*add)[curr+i]) continue;
                else {
                    (*col)[i]=(*sub)[n+curr-i]=(*add)[curr+i]=true;
                    sum+=totalNQueens(curr+1,col,row,sub,add);
                    (*col)[i]=(*sub)[n+curr-i]=(*add)[curr+i]=false;
                }
            }
            return sum;
        } else {
            return 1;
        }
    }
};
