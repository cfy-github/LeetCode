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
        TreeLinkNode *pre=root;
        TreeLinkNode *curr;
        while(pre!=NULL) {
            curr=pre;
            TreeLinkNode *last=NULL;
            TreeLinkNode *first=NULL;
            while(curr!=NULL) {
                if(curr->left!=NULL) {
                    if(last!=NULL) last->next=curr->left;
                    if(first==NULL) first=curr->left;
                    last=curr->left;
                    if(curr->right!=NULL) {
                        curr->left->next=curr->right;
                        last=curr->right;
                    }
                }else if(curr->right!=NULL) {
                    if(first==NULL) first=curr->right;
                    if(last!=NULL) last->next=curr->right;
                    last=curr->right;
                }
                curr=curr->next;
            }
            pre=first;
        }
    }
};
