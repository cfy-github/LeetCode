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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *curr1=l1;
        ListNode *curr2=l2;
        ListNode l(-1);
        ListNode *r = &l;
        while(curr1!=NULL && curr2!=NULL) {
            if(curr1->val<curr2->val) {
                r->next=curr1;
                curr1=curr1->next;
                r=r->next;
            } else {
                r->next=curr2;
                curr2=curr2->next;
                r=r->next;
            }
        }
        if(curr1!=NULL) r->next=curr1;
        if(curr2!=NULL) r->next=curr2;
        return l.next;
    }
};
