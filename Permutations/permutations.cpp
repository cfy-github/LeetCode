class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int n=num.size();
        vector<vector<int> > r;
        for(int i=0;i<n;i++) {
            int c=num[i];
            num.erase(num.begin()+i);
            vector<vector<int> > tmp=permute(c, num);
            num.insert(num.begin()+i,c);
            for(auto &k:tmp) r.push_back(k);
        }
        return r;
    }
    vector<vector<int> > permute(int e, vector<int> &num) {
        vector<vector<int> > r;
        int n=num.size();
        if(n==0) {
            vector<int> s;
            s.push_back(e);
            r.push_back(s);
            return r;
        }
        for(int i=0;i<n;i++) {
            int c=num[i];
            num.erase(num.begin()+i);
            vector<vector<int> > tmp=permute(c,num);
            num.insert(num.begin()+i, c);
            for(auto &k:tmp) r.push_back(k);
        }
        for(auto &k:r) k.insert(k.begin(), e);
        return r;
    }
};
