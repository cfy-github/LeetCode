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
    void reorderList(ListNode *head) {
        if(head==NULL||head->next==NULL) return;
        ListNode *fast=head, *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *l2=slow->next;
        slow->next=NULL;
        ListNode *l1=head;
        reverseList(l2);
        while(l2!=NULL) {
            ListNode *t1=l1->next, *t2=l2->next;
            l1->next=l2;
            l2->next=t1;
            l1=t1;
            l2=t2;
        }
    }
    void reverseList(ListNode *&l) {
        if(l==NULL||l->next==NULL) return;
        ListNode *curr=l, *pre=NULL;
        while(curr!=NULL) {
            ListNode *tmp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=tmp;
        }
        l=pre;
    }
};
