class Solution {
public:
    inline bool valid(char c) {
        return c>'0' && c<='9';
    }
    inline bool zero(char c) {
        return c=='0';
    }
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || zero(s[0])) return 0;
        if(n==1) return 1;
        
        int f[n];
        f[0]=1;
        if(stoi(s.substr(0,2),NULL,10)<27) f[1]=zero(s[1])?1:2;
        else f[1]=zero(s[1])?0:1;
        if(f[1]==0) return 0;
        
        for(int i=2;i<n;++i) {
            if(zero(s[i])) {
                if(s[i-1]<'3' && s[i-1]>'0') f[i]=f[i-2];
                else f[i]=0;
            } else {
                int tmp=stoi(s.substr(i-1,2));
                if(tmp>10 && tmp<27) f[i]=f[i-1]+f[i-2];
                else f[i]=f[i-1];
            }
            if(f[i]==0) return 0;
        }
        return f[n-1];
    }
};
