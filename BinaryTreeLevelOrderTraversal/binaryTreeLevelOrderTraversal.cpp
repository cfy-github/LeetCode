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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<int> lvl;
        vector<vector<int> > r;
        int pre=1, tmp=0;
        queue<const TreeNode *> q;
        const TreeNode *curr=root;
        if(curr!=NULL) q.push(curr);
        while(!q.empty()) {
            curr=q.front();
            q.pop();
            pre--;
            lvl.push_back(curr->val);
            if(curr->left!=NULL) {
                q.push(curr->left);
                tmp++;
            }
            if(curr->right!=NULL) {
                q.push(curr->right);
                tmp++;
            }
            if(pre==0) {
                r.push_back(lvl);
                lvl.clear();
                pre=tmp;
                tmp=0;
            }
        }
        return r;
    }
};
