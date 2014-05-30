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
    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
        else if(root->left==NULL&&root->right==NULL) return root->val;
        else return sumNumbers(root->left,root->val)+sumNumbers(root->right,root->val);
    }
    int sumNumbers(TreeNode *root, int sum) {
        if(root==NULL) return 0;
        else if(root->left==NULL && root->right==NULL) return sum*10+root->val;
        else {
            sum=sum*10+root->val;
            return sumNumbers(root->left,sum)+sumNumbers(root->right,sum);
        }
    }
};
