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
    int depth(const TreeNode *root) {
        if(root==NULL) return 0;
        else return max(depth(root->left),depth(root->right))+1;
    }
    bool isBalanced(TreeNode *root) {
        stack<const TreeNode *> s;
        if(root!=NULL) s.push(root);
        const TreeNode *curr;
        while(!s.empty()) {
            curr=s.top();
            s.pop();
            if(abs(depth(curr->left)-depth(curr->right))>1) return false;
            if(curr->right!=NULL) s.push(curr->right);
            if(curr->left!=NULL) s.push(curr->left);
        }
        return true;
    }
};
