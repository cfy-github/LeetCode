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
        if(head==NULL || head->next==NULL) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *curr=head->next;
        while(curr!=NULL) {
            while(curr!=NULL && curr->val==prev->next->val) {
                curr=curr->next;
            }
            if(prev->next->next==curr) {
                prev=prev->next;
                curr=curr->next;
            } else {
                prev->next=curr;
                if(curr==NULL) break;
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};
