/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        for(ListNode *p=head;p!=NULL;p=p->next) len++;
        return sortedListToBST(head, 0, len-1);
    }
private:
    TreeNode *sortedListToBST(ListNode *&curr, int start, int end) {
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode *left=sortedListToBST(curr,start,mid-1);
        TreeNode *p=new TreeNode(curr->val);
        p->left=left;
        curr=curr->next;
        p->right=sortedListToBST(curr,mid+1,end);
        return p;
    }
};
