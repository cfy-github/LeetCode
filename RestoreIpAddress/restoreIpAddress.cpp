class Solution {
public:
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        string ip_str;
        int n=s.size();
        int cnt=0;
        if(n>12||n<4) return r;
        dfs(ip_str, r, 0, s, cnt);
        return r;
    }
    void dfs(string ip, vector<string> &r, int i, string &s, int c) {
        int n=s.size();
        if(c==3) {
            if(n-i>0 && n-i<=3) {
                if(n-i>1&&s[i]=='0') return;
                int tmp=atoi(s.substr(i,n-i).c_str());
                if(tmp<=255) {
                    ip+=(s.substr(i,n-i));
                    r.push_back(ip);
                }
            }
        } else {
            if(s[i]=='0') dfs(ip+"0.", r, i+1, s, c+1);
            else {
                for(int j=1;i+j-1<n&&j<4;++j) {
                    int tmp=atoi(s.substr(i,j).c_str());
                    if(tmp<=255) dfs(ip+s.substr(i,j)+".", r, i+j, s, c+1);
                }
            }
        }
    }
};
