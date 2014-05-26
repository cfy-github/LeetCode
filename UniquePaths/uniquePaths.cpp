class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n) swap(m,n);
        if(m<=1) return 1;
        long long a=1, b=1;
        for(int i=1;i<m;i++) {
            a*=(n+i-1);
            b*=i;
        }
        return a/b;
    }
};
