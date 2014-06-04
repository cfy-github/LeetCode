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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int > > r;
        queue<const TreeNode *> q;
        bool flag=true;
        int cnt=0, num;
        if(root!=NULL) {
            num=1;
            q.push(root);
        }
        vector<int> v;
        while(!q.empty()) {
            const TreeNode *curr=q.front();
            if(curr->left!=NULL) {
                cnt++;
                q.push(curr->left);
            }
            if(curr->right!=NULL) {
                cnt++;
                q.push(curr->right);
            }
            num--;
            q.pop();
            v.push_back(curr->val);
            if(num==0) {
                if(!flag) reverse(v.begin(),v.end());
                r.push_back(v);
                num=cnt;
                cnt=0;
                flag=!flag;
                v.clear();
            }
        }
        return r;
    }
};
