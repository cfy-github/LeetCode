class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > r;
        set<vector<int> > s;
        vector<int> curr;
        size_t n=S.size();
        size_t len=1U<<n;
        for(size_t i=0;i<len;++i) {
            for(size_t j=0;j<n;j++) {
                if(1U<<j & i) curr.push_back(S[j]);
            }
            s.insert(curr);
            curr.clear();
        }
        copy(s.begin(), s.end(), back_inserter(r));
        return r;
    }
};
