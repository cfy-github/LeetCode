/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
struct myclass {
  bool operator() (const ListNode *a, const ListNode *b) { return a->val>b->val; }
} myobj;   
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode dummy(-1);
        ListNode *curr, *pre=&dummy;
        //for(int i=0;i<n;i++) if(lists[i]==NULL) lists.erase(lists.begin()+i);
        for(auto it=lists.begin();it!=lists.end();) {
            if(*it==NULL) {
                lists.erase(it);
            } else it++;
        }
        if(lists.empty()) return NULL;
        make_heap(lists.begin(),lists.end(),myobj);
        while(!lists.empty()) {
            curr=lists.front();
            pre->next=curr;
            pre=curr;
            pop_heap(lists.begin(),lists.end(),myobj);
            lists.pop_back();
            curr=curr->next;
            if(curr!=NULL) {
                lists.push_back(curr);
                push_heap(lists.begin(),lists.end(),myobj);
            }
        }
        return dummy.next;
    }
};
