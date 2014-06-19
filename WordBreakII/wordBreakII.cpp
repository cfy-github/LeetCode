class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> r;
        
        int n=s.size();
        bool f[n+1];
        vector<vector<bool> > prev(n+1, vector<bool>(n+1, false));
        fill_n(&f[0],n+1,false);
        f[0]=true;
        for(int i=1;i<=n;++i) {
            for(int j=i-1; j>=0; --j) {
                if(f[j] && dict.find(s.substr(j, i-j))!=dict.end()) {
                    f[i]=true;
                    prev[i][j]=true;
                }
            }
        }
        vector<string> p;
        genPath(s, prev, n, r, p);
        return r;
    }
    void genPath(string &s, vector<vector<bool> > &prev, int curr, vector<string> &r, vector<string> &p) {
        if(curr==0) {
            string str;
            for(int i=p.size()-1;i>=0;--i) str+=(p[i]+" ");
            str.erase(str.size()-1, 1);
            r.push_back(str);
        }
        for(int i=0;i<curr;++i) {
            if(prev[curr][i]) {
                p.push_back(s.substr(i, curr-i));
                genPath(s, prev, i, r, p);
                p.pop_back();
            }
        }
    }
};
