class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > r;
        for(int i=0;i<numRows;i++) {
            vector<int> curr(i+1);
            r.push_back(curr);
            for(int j=0;j<=i;j++) {
                r[i][j]=(i==0||j==0||i==j)?1:(r[i-1][j]+r[i-1][j-1]);
            }
        }
        return r;
    }
};
