class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n+1);
        if(n<0) return 0;
        v[0]=1;
        v[1]=1;
        if(n>=2) {
            for(int i=2;i<=n;i++) {
                v[i]=v[i-2]+v[i-1];
            }
        }
        return v[n];
    }
};
