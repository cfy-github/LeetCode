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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> r;
        const TreeNode* curr;
        stack<const TreeNode*> s;
        curr=root;
        if(curr!=NULL) s.push(curr);
        while(!s.empty()) {
            curr=s.top();
            s.pop();
            r.push_back(curr->val);
            if(curr->right!=NULL) s.push(curr->right);
            if(curr->left!=NULL) s.push(curr->left);
        }
        return r;
    }
};
