class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
        int cnt=1<<n;
        r.reserve(cnt);
        for(int i=0;i<cnt;i++) {
            r.push_back(i^(i>>1));
        }
        return r;
    }
};
