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
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        else if(root->left==NULL && root->right==NULL) return 1;
        else return min(minDepth(root->left,1),minDepth(root->right,1));
    }
    int minDepth(TreeNode *root, int d) {
        if(root==NULL) return INT_MAX;
        else if(root->left==NULL && root->right==NULL) return d+1;
        else return min(minDepth(root->left,d+1),minDepth(root->right,d+1));
    }
};
