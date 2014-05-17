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
    bool isSymmetric(const TreeNode *l, const TreeNode *r) {
        if(l==r) return true;
        else if(l!=NULL && r!=NULL && l->val==r->val) {
            return (isSymmetric(l->left, r->right) && isSymmetric(l->right,r->left));
        } else return false;
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return isSymmetric(root->left,root->right);
    }
};
