class Solution {
public:
    int candy(vector<int> &ratings) {
        //if(ratings.size()<2) return ratings.size();
        int n=ratings.size();
        int incre[n];
        fill_n(&incre[0],n,0);
        for(int i=1, inc=1;i<n;++i) {
            if(ratings[i]>ratings[i-1]) {
                incre[i]=max(inc++, incre[i]);
            } else {
                inc=1;
            }
        }
        for(int i=n-2, inc=1;i>=0;--i) {
            if(ratings[i]>ratings[i+1]) {
                incre[i]=max(inc++, incre[i]);
            } else inc=1;
        }
        return accumulate(&incre[0],&incre[0]+n,n);
    }
};
