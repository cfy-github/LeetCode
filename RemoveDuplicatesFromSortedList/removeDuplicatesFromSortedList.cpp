/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pre=head;
        if(head==NULL) return head;
        ListNode *curr=head->next;
        while(curr!=NULL) {
            if(pre->val==curr->val) {
                pre->next=curr->next;
                curr=pre->next;
            } else {
                pre=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};
