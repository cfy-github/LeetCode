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
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;
        int m=INT_MIN, lMax=0, rMax=0;
        btt(root->left, m, lMax);
        btt(root->right, m, rMax);
        int tmpLv=root->val+lMax;
        int tmpRv=root->val+rMax;
        int tmpAll=tmpLv+rMax;
        return max(m, max(tmpAll, max(root->val, max(tmpLv, tmpRv))));
    }
    void btt(TreeNode *root, int &m, int &p) {
        if(root==NULL) {p=0;return;}
        int v=root->val, lm=0, rm=0;
        btt(root->left, m, lm);
        btt(root->right, m, rm);
        int lv=lm+v, rv=rm+v, all=lv+rm;
        p=max(v,max(lv,rv));
        m=max(m,max(all,p));
    }
};
