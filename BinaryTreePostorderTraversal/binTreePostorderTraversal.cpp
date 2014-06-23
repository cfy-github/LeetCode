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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> r;
        if(root==NULL) return r;
        
        stack<TreeNode *> s;
        TreeNode *curr=root, *pre;
        do {
            while(curr!=NULL) {
                s.push(curr);
                curr=curr->left;
            }
            pre=NULL;
            while(!s.empty()) {
                curr=s.top();
                s.pop();
                if(curr->right==pre) {
                    r.push_back(curr->val);
                    pre=curr;
                } else {
                    s.push(curr);
                    curr=curr->right;
                    break;
                }
            }
        } while(!s.empty());
        return r;
    }
};
