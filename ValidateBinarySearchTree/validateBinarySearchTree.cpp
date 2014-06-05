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
    bool isValidBST(TreeNode *root) {
        if(root==NULL) return true;
        int pre=INT_MIN;
        return isValidBST(root, pre);
    }
    bool isValidBST(TreeNode *root, int &pre) {
        bool ret=true;
        if(root->left!=NULL) ret=isValidBST(root->left, pre);
        if(!ret) return ret;
        if(root->val<=pre) return false;
        else {
            pre=root->val;
            if(root->right!=NULL) ret=isValidBST(root->right,pre);
        }
        return ret;
    }
};
