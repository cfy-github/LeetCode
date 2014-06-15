class Solution {
    //p[i]-->s[i,n-1]
    //p[i]=min(p(j+1)+1) (i<=j<n-1)
public:
    int minCut(string s) {
        size_t n=s.size();
        if(n<2) return 0;
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);
        int p[n];
        fill_n(&p[0], n, n);
        for(int i=0;i<n;++i) f[i][i]=true;
        for(int i=0;i<n-1;++i) f[i][i+1]=s[i]==s[i+1];
        for(int k=2;k<n;++k) {
            for(int i=0;i<n-k;++i) f[i][i+k]=f[i+1][i+k-1] && (s[i]==s[i+k]);
        }
        p[n-1]=0;
        for(int i=n-2;i>=0;--i) {
            if(f[i][n-1]) {p[i]=0; continue;}
            for(int j=n-2;j>=i;--j) {
                if(f[i][j]) p[i]=min(p[i],p[j+1]+1);
            }
        }
        return p[0];
    }
};
