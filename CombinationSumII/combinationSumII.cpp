class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > r;
        set<vector<int> > s;
        vector<int> v;
        dfs(s,v,0,num,target);
        copy(s.begin(),s.end(),back_inserter(r));
        return r;
    }
    void dfs(set<vector<int> > &s, vector<int> &v, int first, vector<int> &num, int gap) {
        if(gap==0) {
            s.insert(v);
            return;
        }
        if(first==num.size()) return;
        for(int i=first;i<num.size();i++) {
            if(gap<num[i]) return;
            v.push_back(num[i]);
            dfs(s,v,i+1,num,gap-num[i]);
            v.pop_back();
        }
    }
};
