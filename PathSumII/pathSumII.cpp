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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > r;
        vector<int> curr;
        if(root==NULL) return r;
        else if(root->left==NULL && root->right==NULL && sum==root->val) {
            curr.push_back(root->val);
            r.push_back(curr);
            return r;
        }
        else {
            curr.push_back(root->val);
            pathSum(r, curr, root->left, sum-root->val);
            pathSum(r, curr, root->right, sum-root->val);
            curr.pop_back();
            return r;
        }
    }
    void pathSum(vector<vector<int> > &r, vector<int> &curr, TreeNode *root, int sum) {
        if(root==NULL) return;
        else if(root->left==NULL&&root->right==NULL&&sum==root->val) {
            curr.push_back(root->val);
            r.push_back(curr);
            curr.pop_back();
            return;
        } else {
            curr.push_back(root->val);
            pathSum(r, curr, root->left, sum-root->val);
            pathSum(r, curr, root->right, sum-root->val);
            curr.pop_back();
        }
    }
};
