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
    void flatten(TreeNode *root) {
        TreeNode *curr=root;
        //TreeNode *tmp;
        while(curr!=NULL) {
            if(curr->left==NULL) {
                curr=curr->right;
            } else if(curr->right==NULL) {
                curr->right=curr->left;
                curr->left=NULL;
            } else {
                TreeNode *pre=curr->left;
                while(pre->left!=NULL||pre->right!=NULL) {
                    if(pre->right!=NULL) pre=pre->right;
                    else pre=pre->left;
                }
                pre->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                curr=curr->right;
            }
        }
    }
};
