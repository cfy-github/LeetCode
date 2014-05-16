/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *pre;
        pre=root;
        while(pre!=NULL) {
            TreeLinkNode *curr=pre;
            while(curr!=NULL) {
                if(curr->left!=NULL)curr->left->next=curr->right;
                if(curr->next!=NULL && curr->right!=NULL) curr->right->next=curr->next->left;
                curr=curr->next;
            }
            pre=pre->left;
        }
    }
};
