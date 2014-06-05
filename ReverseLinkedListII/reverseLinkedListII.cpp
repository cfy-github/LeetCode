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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *pre=&dummy;
        ListNode *pm=head, *pn=head;
        for(int gap=n-m;gap>0;--gap) pn=pn->next;
        for(;m-1>0;--m) {
            pre=pre->next;
            pn=pn->next;
            pm=pm->next;
        }
        pre->next=pn;
        ListNode *curr=pm->next;
        pm->next=pn->next;
        while(curr!=pn) {
            ListNode *tmp=curr->next;
            curr->next=pm;
            pm=curr;
            curr=tmp;
        }
        curr->next=pm;
        return dummy.next;
    }
};
