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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        queue<const TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        const TreeNode *curr1, *curr2;
        while(!q1.empty()) {
            curr1=q1.front();
            curr2=q2.front();
            q1.pop();
            q2.pop();
            if(curr1!=NULL && curr2!=NULL && curr1->val==curr2->val) {
                q1.push(curr1->left); q1.push(curr1->right);
                q2.push(curr2->right);q2.push(curr2->left);
            } else if(curr1==curr2) {
                //Do nothing
            } else return false;
        }
        return true;
    }
};
