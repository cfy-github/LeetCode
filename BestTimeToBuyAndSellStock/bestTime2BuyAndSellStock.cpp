class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n<=1) return 0;
        int max=0;
        int minId=0;
        int minId2=0;
        for(int i=1;i<n;i++) {
            int tmp=prices[i]-prices[minId];
            int tmp2=prices[i]-prices[minId2];
            if(tmp2<0) {
                minId2=i;
            } else {
                max=max<tmp2?tmp2:max;
                minId=minId2;
            }
        }
        return max;
    }
};
