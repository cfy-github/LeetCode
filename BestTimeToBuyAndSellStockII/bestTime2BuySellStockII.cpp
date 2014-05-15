class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //bool flag=true;
        int r=0;
        int size=prices.size();
        if(size<=1) return 0;
        int last=prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i]>last) r+=(prices[i]-last);
            last=prices[i];
        }
        return r;
    }
};
