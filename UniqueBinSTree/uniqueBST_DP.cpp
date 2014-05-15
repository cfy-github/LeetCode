class Solution {
public:
    int numTrees(int n) {
        vector<int> d(n+1, 0);
        d[0]=1;
        d[1]=1;
        for(int i=2;i<=n;i++) {
            for(int j=0;j<i;j++) d[i]+=(d[j]*d[i-1-j]);
        }
        return d[n];
    }
};
