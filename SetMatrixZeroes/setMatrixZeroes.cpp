class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        bool rflag=false, cflag=false;
        for(int i=0;i<n;i++) {
            if(matrix[0][i]==0) rflag=true;
        }
        for(int i=0;i<m;i++) {
            if(matrix[i][0]==0) cflag=true;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++) {
            if(matrix[0][i]==0) {
                for(int j=1;j<m;j++) matrix[j][i]=0;
            }
        }
        for(int j=1;j<m;j++) {
            if(matrix[j][0]==0) {
                for(int i=1;i<n;i++) matrix[j][i]=0;
            }
        }
        if(rflag) {
            for(int i=0;i<n;i++) matrix[0][i]=0;
        }
        if(cflag) {
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
    }
};
