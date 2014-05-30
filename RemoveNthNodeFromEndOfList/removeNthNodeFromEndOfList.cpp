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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast=head, *slow=head;
        while(fast!=NULL) {
            n--;
            if(n==0) break;
            fast=fast->next;
        }
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *pre=&dummy;
        while(fast->next!=NULL) {
            fast=fast->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=slow->next;
        return dummy.next;
    }
};
