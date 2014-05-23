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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        const TreeNode *curr=root;
        queue<const TreeNode *> q;
        if(curr!=NULL) q.push(curr);
        vector<int> cv;
        vector<vector<int> > r;
        int pre=1;
        int cnt=0;
        while(!q.empty()) {
            curr=q.front();
            q.pop();
            cv.push_back(curr->val);
            pre--;
            if(curr->left!=NULL) {
                q.push(curr->left);
                cnt++;
            }
            if(curr->right!=NULL) {
                q.push(curr->right);
                cnt++;
            }
            if(pre==0) {
                r.insert(r.begin(), cv);
                pre=cnt;
                cnt=0;
                cv.clear();
            }
        }
        return r;
    }
};
