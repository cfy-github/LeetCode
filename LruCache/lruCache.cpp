class LRUCache{
    struct ListNode{
        int key;
        int val;
        ListNode *next;
        ListNode(int k, int v): key(k), val(v), next(NULL) {}
    };
private:
    map<int, ListNode *> m;
    ListNode *tail;
    ListNode *head;
    int cap;
public:
    LRUCache(int capacity) {
        head=new ListNode(-1,-1);
        cap=capacity;
        tail=head;
    }
    
    int get(int key) {
        int r=-1;
        auto it=m.find(key);
        if(it!=m.end()) {
            ListNode *prev=it->second;
            ListNode *curr=prev->next;
            r=curr->val;
            if(curr!=tail) {
                prev->next=curr->next;
                m[prev->next->key]=prev;
                curr->next=NULL;
                tail->next=curr;
                m[curr->key]=tail;
                tail=curr;
            }
        }
        return r;
    }
    
    void set(int key, int value) {
        auto it=m.find(key);
        if(it!=m.end()) {
            ListNode *prev=it->second;
            ListNode *curr=prev->next;
            curr->val=value;
            if(curr!=tail) {
                prev->next=curr->next;
                m[prev->next->key]=prev;
                curr->next=NULL;
                tail->next=curr;
                m[curr->key]=tail;
                tail=curr;
            }
        } else {
            if(m.size()==cap) {
                ListNode *curr=head->next;
                head->next=curr->next;
                
                if(curr==tail) tail=head;
                else m[head->next->key]=head;
                
                m.erase(curr->key);
                delete curr;
            }
            m[key]=tail;
            tail->next=new ListNode(key, value);
            tail=tail->next;
        }
    }
};
