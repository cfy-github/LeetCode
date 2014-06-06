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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *curr=head;
        if(curr==NULL) return head;
        ListNode *p;
        while(curr->next!=NULL) {
            p=curr->next;
            ListNode *ins=&dummy;
            while(ins->next!=p) {
                if(p->val<=ins->next->val) {
                    ListNode *tmp=ins->next;
                    ins->next=p;
                    curr->next=p->next;
                    p->next=tmp;
                    break;
                } else ins=ins->next;
            }
            if(curr->next==p) curr=curr->next;
        }
        return dummy.next;
    }
};
