class Solution {
public:
    vector<vector<string> > partition(string s) {
        const int n=s.size();
        bool is[n][n];
        fill_n(&is[0][0], n*n, false);
        for(int i=n-1;i>=0;--i) {
            for(int j=i;j<n;j++) is[i][j]=s[i]==s[j] && (j-i<2 || is[i+1][j-1]);
        }
        vector<vector<string> > d[n];
        for(int i=n-1;i>=0;--i) {
            for(int j=i;j<n;j++) {
                if(is[i][j]) {
                    const string pal=s.substr(i,j-i+1);
                    if(j+1<n) {
                        for(auto v:d[j+1]) {
                            v.insert(v.begin(),pal);
                            d[i].push_back(v);
                        }
                    } else d[i].push_back(vector<string> {pal});
                }
            }
        }
        return d[0];
    }
};
