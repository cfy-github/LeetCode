class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > list;
        vector<int> path;
        dfs(list, path, n, k, 1);
        return list;
    }
    void dfs(vector<vector<int> > &l, vector<int> &path, int n, int k, int begin) {
        if(k==0) {
            l.push_back(path);
            return;
        }
        for(int i=begin;i<=n;i++) {
            path.push_back(i);
            dfs(l,path,n,k-1,i+1);
            path.pop_back();
        }
    }
};
