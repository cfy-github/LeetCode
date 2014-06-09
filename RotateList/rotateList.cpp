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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL||head->next==NULL||k==0) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy, *curr=head;
        int l=0;
        while(curr->next!=NULL) {
            l++;
            curr=curr->next;
        }
        l++;
        if(k%l==0) return head;
        ListNode *last=curr;
        last->next=dummy.next;
        int steps=l-k%l;
        while(steps) {
            steps--;
            curr=curr->next;
        }
        dummy.next=curr->next;
        curr->next=NULL;
        return dummy.next;
    }
};
