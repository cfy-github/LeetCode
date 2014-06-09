class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int n=prices.size();
        if(n<=1) return 0;
        vector<int> f(n,0), g(n,0);
        
        for(int i=1, valley=prices[0];i<n;++i) {
            valley=min(valley,prices[i]);
            f[i]=max(f[i-1], prices[i]-valley);
        }
        
        for(int i=n-2, peak=prices[n-1];i>=0;--i) {
            peak=max(peak, prices[i]);
            g[i]=max(g[i+1], peak-prices[i]);
        }
        int r=0;
        for(int i=0;i<n;++i) r=max(f[i]+g[i],r);
        return r;
    }
};
