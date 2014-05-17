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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *pre=&dummy;
        ListNode *curr=head;
        ListNode *next;
        while(curr!=NULL&&curr->next!=NULL) {
            next=curr->next;
            curr->next=next->next;
            next->next=curr;
            pre->next=next;
            pre=curr;
            curr=curr->next;
        }
        return dummy.next;
    }
};
