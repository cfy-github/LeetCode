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
    void recoverTree(TreeNode *root) {
        TreeNode *prev=NULL, *curr=root;
        pair<TreeNode *, TreeNode *> broken;
        int id=0;
        while(curr!=NULL) {
            if(curr->left==NULL) {
                detect(broken, prev, curr);
                prev=curr;
                curr=curr->right;
            } else {
                auto p=curr->left;
                for(;p->right!=NULL&&p->right!=curr;p=p->right);
                if(p->right==NULL) {
                    p->right=curr;
                    curr=curr->left;
                } else {
                    detect(broken, prev, curr);
                    p->right=NULL;
                    prev=curr;
                    curr=curr->right;
                }
            }
        }
        swap(broken.first->val,broken.second->val);
    }
    inline void detect(pair<TreeNode *, TreeNode *> &br, TreeNode *prev, TreeNode *curr) {
        if(prev!=NULL&&prev->val>curr->val) {
            if(br.first==NULL) br.first=prev;
            br.second=curr;
        }
    }
};
