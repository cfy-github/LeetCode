class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> r;
        int n=L.size();
        if(n==0) return r;
        int l=L[0].size();
        if(S.size()<l*n) return r;
        
        unordered_map<string, int> m;
        for(const auto &e:L) {
            if(m.find(e)==m.end()) m[e]=1;
            else m[e]+=1;
        }
        
        for(int i=0;i<S.size()-l+1;++i) {
            auto tit=m.find(S.substr(i,l));
            if(tit!=m.end()) {
                stack<string> st;
                tit->second--;
                st.push(tit->first);
                int cnt=1;
                int j=i+l;
                while(j<S.size()-l+1) {
                    auto it=m.find(S.substr(j,l));
                    if(it!=m.end() && it->second>0) {st.push(it->first);it->second--;cnt++;}
                    else break;
                    j+=l;
                }
                if(cnt==n) r.push_back(i);
                while(!st.empty()) {
                    auto sss=st.top();
                    st.pop();
                    m[sss]++;
                }
            }
        }
        return r;
    }
};
