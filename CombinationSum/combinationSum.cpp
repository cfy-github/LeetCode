class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > r;
        vector<int> v;
        combinationSum(candidates, target, 0, v, r);
        return r;
    }
    void combinationSum(vector<int> &can, int gap, int first, vector<int> &v, vector<vector<int> > &r) {
        if(gap==0) {
            r.push_back(v);
            return;
        }
        for(int i=first;i<can.size();i++) {
            if(gap<can[i]) return;
            v.push_back(can[i]);
            combinationSum(can,gap-can[i],i,v,r);
            v.pop_back();
        }
    }
};
