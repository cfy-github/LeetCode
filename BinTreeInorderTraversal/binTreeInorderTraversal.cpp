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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r;
        const TreeNode* curr;
        stack<const TreeNode*> s;
        curr=root;
        
        while(curr!=NULL || !s.empty()) {
            if(curr!=NULL) {
                s.push(curr);
                curr=curr->left;
            } else {
                curr=s.top();
                s.pop();
                r.push_back(curr->val);
                curr=curr->right;
            }
        }
        return r;
    }
};
