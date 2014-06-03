/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<int> v;
        vector<TreeNode *> r;
        if(n==0) {
            r.push_back(NULL);
            return r;
        }
        for(int i=1;i<=n;++i) v.push_back(i);
        for(int i=0;i<n;i++) {
            vector<TreeNode *> list=generateTrees(i,0,n,v);
            //copy(list.begin(),list.end(),back_inserter(r));
            for(auto l:list) r.push_back(l);
        }
        return r;
    }
    vector<TreeNode *> generateTrees(int rt, int begin, int end, vector<int> &v) {
        vector<TreeNode *> r;
        if(begin<end) {
            vector<TreeNode *> ll;
            vector<TreeNode *> rl;
            for(int i=begin;i<rt;i++) {
                vector<TreeNode *> currL=generateTrees(i,begin,rt,v);
                for(auto s:currL) ll.push_back(s);
            }
            if(rt==begin) ll.push_back(NULL);
            for(int i=rt+1;i<end;i++) {
                vector<TreeNode *> currR=generateTrees(i,rt+1,end,v);
                for(auto s:currR) rl.push_back(s);
            }
            if(end==rt+1) rl.push_back(NULL);
            for(auto left:ll) {
                for(auto right:rl) {
                    TreeNode *curr=new TreeNode(v[rt]);
                    curr->left=left;
                    curr->right=right;
                    r.push_back(curr);
                }
            }
        } else {
            r.push_back(NULL);
        }
        return r;
    }
};
