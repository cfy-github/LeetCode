class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        size_t n=S.size();
        sort(S.begin(),S.end());
        vector<vector<int> > r;
        vector<int> curr;
        int max=1<<n;
        for(size_t i=0;i<max;i++) {
            int tmp=i;
            for(size_t j=0;j<n;j++) {
                if(tmp%2) curr.push_back(S[j]);
                tmp=tmp>>1;
            }
            r.push_back(curr);
            curr.clear();
        }
        return r;
    }
};
