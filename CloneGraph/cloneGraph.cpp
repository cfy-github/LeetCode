/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> func;
        stack<UndirectedGraphNode *> st;
        UndirectedGraphNode *curr=node;
        st.push(curr);
        while(!st.empty()) {
            curr=st.top();
            st.pop();
            func[curr]=new UndirectedGraphNode(curr->label);
            for(auto nb:curr->neighbors) {
                if(func.find(nb)==func.end()) {
                    st.push(nb);
                }
            }
        }
        for(auto it=func.begin();it!=func.end();++it) {
            for(auto nb:it->first->neighbors) {
                it->second->neighbors.push_back(func[nb]);
            }
        }
        return func[node];
    }
};
