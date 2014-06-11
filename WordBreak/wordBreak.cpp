class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=dict.size();
        if(s.size()==0) return true;
        if(n==0) return false;
        vector<bool> f(s.size()+1, false);
        f[0]=true;
        for(int i=1;i<=s.size();++i) {
            for(int j=i-1;j>=0;--j) {
                if(f[j]&&dict.find(s.substr(j,i-j))!=dict.end()) {f[i]=true;break;}
            }
        }
        return f[s.size()];
    }
};
