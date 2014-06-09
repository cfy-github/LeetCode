class Solution {
public:
    string getPermutation(int n, int k) {
        string r;
        vector<int> f(n+1,1);
        vector<int> A(n,1);
        for(int i=1;i<=n;++i) {
            f[i]=i*f[i-1];
            A[i-1]=i;
        }
        k--;
        k%=f[n];
        for(int i=n-1;i>=1;--i) {
            int c=k/f[i];
            k=k%f[i];
            r+=('0'+A[c]);
            A.erase(A.begin()+c);
        }
        r+=('0'+A[0]);
        return r;
    }
};
