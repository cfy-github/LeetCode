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
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *tmp=slow->next;
        slow->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(tmp);
        return mergeSortedList(l1,l2);
    }
    ListNode *mergeSortedList(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *pre=&dummy;
        while(l1!=NULL&&l2!=NULL) {
            if(l1->val<l2->val) {
                pre->next=l1;
                pre=l1;
                l1=l1->next;
            } else {
                pre->next=l2;
                pre=l2;
                l2=l2->next;
            }
        }
        while(l1!=NULL) {pre->next=l1;pre=l1;l1=l1->next;}
        while(l2!=NULL) {pre->next=l2;pre=l2;l2=l2->next;}
        return dummy.next;
    }
};
