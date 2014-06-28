class Solution {
public:
    string getPermutation(int n, int k) {
        string r;
        vector<char> v;
        vector<int> f(n+1, 1);
        for(int i=1;i<=n;++i) {
            v.push_back(i+'0');
            f[i]=i*f[i-1];
        }
        int curr=(k-1)%f[n];
        for(int i=n-1;i>=0;curr%=f[i], --i) {
            int tmp=curr/f[i];
            r+=v[tmp];
            v.erase(v.begin()+tmp);
        }
        return r;
    }
};
