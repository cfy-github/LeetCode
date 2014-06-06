class Solution {
/*  minDist(w1[0,i],w2[0,j])=
*   f[i][j]
        =f[i-1]f[j-1](w1[i]==w2[j])
        =f[i]f[j-1]+1 or f[i-1]f[j]+1 (insert)
        =f[i-1]f[j-1]+1 (replace)
        =f[i-1]f[j]+1 or ....
*/
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<int> d(n+1,0);
        for(int i=0;i<=n;i++) d[i]=i;
        for(int i=1;i<=m;i++) {
            int pre=d[0];
            d[0]=i;
            for(int j=1;j<=n;j++) {
                if(word1[i-1]==word2[j-1]) {
                    swap(pre,d[j]);
                } else {
                    int mini=min(d[j-1],d[j]);
                    int tmp=d[j];
                    d[j]=1+min(mini,pre);
                    pre=tmp;
                }
            }
        }
        return d[n];
    }
};
