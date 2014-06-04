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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *ins=&dummy;
        ListNode *pre=ins;
        ListNode *curr=head;
        while(curr!=NULL) {
            ListNode *next=curr->next;
            if(curr->val<x) {
                if(ins->next!=curr) {
                    pre->next=curr->next;
                    curr->next=ins->next;
                    ins->next=curr;
                } else pre=pre->next;
                ins=curr;
                curr=next;
            } else {
                pre=pre->next;
                curr=next;
            }
        }
        return dummy.next;
    }
};
