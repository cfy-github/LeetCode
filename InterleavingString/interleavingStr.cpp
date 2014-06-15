class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        if(s1.size()<s2.size()) return isInterleave(s2, s1, s3);
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        bool f[n2+1];
        fill_n(&f[0], n2+1, false);
        f[0]=true;
        for(int i=1;i<=n2;i++) {
            f[i]=(s2[i-1]==s3[i-1])&&f[i-1];
            if(!f[i]) break;
        }
        for(int i=1;i<=n1;i++) {
            f[0]=(s1[i-1]==s3[i-1])&&f[0];
            for(int j=1;j<=n2;++j) {
                f[j]=(f[j-1] && s2[j-1]==s3[i+j-1]) || (f[j] && s1[i-1]==s3[i+j-1]);
            }
        }
        return f[n2];
    }
};
