class Solution {
public:
    int numDistinct(string S, string T) {
        int ns=S.size();
        int nt=T.size();
        if(nt>ns) return 0;
        vector<int> d(nt+1,0);
        d[0]=1;
        for(int j=1;j<=nt;j++) d[j]=0;
        for(int i=1;i<=ns;i++) {
            int pre=d[0];
            for(int j=1;j<=i&&j<=nt;j++) {
                int tmp=d[j];
                if(S[i-1]==T[j-1]) {
                    d[j]=pre+d[j];
                    pre=tmp;
                } else pre=d[j];
            }
        }
        return d[nt];
    }
};
