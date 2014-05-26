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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        ListNode *slow2=NULL;
        while(fast!=NULL && fast->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) {
                slow2=head;
                break;
            }
        }
        while(slow2!=NULL && slow2!=slow) {
            slow2=slow2->next;
            slow=slow->next;
        }
        return slow2;
    }
};
