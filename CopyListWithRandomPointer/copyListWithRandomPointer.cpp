/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode dummy(-1);
        RandomListNode *p=&dummy, *curr=head;
        unordered_map<RandomListNode *, RandomListNode *> func;
        for(;curr!=NULL;curr=curr->next,p=p->next) {
            p->next=new RandomListNode(curr->label);
            func[curr]=p->next;
        }
        curr=head;
        p=dummy.next;
        for(;curr!=NULL;curr=curr->next, p=p->next) p->random=func[curr->random];
        return dummy.next;
    }
};
