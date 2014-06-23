class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> st;
        queue<int> q;
        string r;
        int n=S.size();
        int m=T.size();
        if(n==0||m==0) return r;
        for(int i=0;i<m;++i) {
            if(st.find(T[i])==st.end()) st[T[i]]=-1;
            else st[T[i]]--;
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            auto it = st.find(S[i]);
            if(it!=st.end()) {
                if(cnt<m) {
                    if(it->second<0) cnt++;
                    it->second++;
                    q.push(i);
                    if(cnt==m)  {
                        int tmp=q.front();
                        while(st[S[tmp]]>0) {
                            q.pop();
                            st[S[tmp]]--;
                            tmp=q.front();
                        }
                        r=S.substr(tmp, i-tmp+1);
                    }
                } else {
                    int s=q.front();
                    q.push(i);
                    if(S[s]==S[i]) {
                        q.pop();
                        int tmp=q.front();
                        while(st[S[tmp]]>0) {
                            st[S[tmp]]--;
                            q.pop();
                            tmp=q.front();
                        }
                        if(r.size()==0 || r.size()>i-tmp+1) r=S.substr(tmp, i-tmp+1);
                    } else it->second++;
                }
            }
        }
        return r;
    }
};
