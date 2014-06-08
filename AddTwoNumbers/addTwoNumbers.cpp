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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry=0;
        ListNode dummy(-1);
        ListNode *p1=l1, *p2=l2, *p3=&dummy;
        while(p1!=NULL&&p2!=NULL) {
            int sum=p1->val+p2->val+carry;
            p3->next=new ListNode(sum%10);
            carry=sum/10;
            p3=p3->next;
            p1=p1->next;
            p2=p2->next;
        }
        for(;p1!=NULL;p1=p1->next,p3=p3->next) {
            int sum=p1->val+carry;
            p3->next=new ListNode(sum%10);
            carry=sum/10;
        }
        for(;p2!=NULL;p2=p2->next,p3=p3->next) {
            int sum=p2->val+carry;
            p3->next=new ListNode(sum%10);
            carry=sum/10;
        }
        if(carry) p3->next=new ListNode(1);
        return dummy.next;
    }
};
