class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1||(s.size()==2 && s[0]==s[1])) return s;
        //vector<vector<bool> > f(s.size(), vector<bool>(s.size(),false));
        bool f[s.size()][s.size()];
        fill_n(&f[0][0],s.size()*s.size(),false);
        int max_len=1, max_id=0;
        for(int k=0;k<s.size();k++) {
            for(int i=0;i<s.size()-k;i++) {
                if(k==0||(k==1 && s[i]==s[i+1])) f[i][i+k]=true;
                else if(k>1) f[i][i+k]=f[i+1][i+k-1]&&(s[i]==s[i+k]);
                if(f[i][i+k]) {max_len=k+1;max_id=i;}
            }
        }
        return s.substr(max_id,max_len);
    }
};
