class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;++i) {
            if(isspace(s[i])) {
                if(cnt!=0) st.push(s.substr(i-cnt, cnt));
                cnt=0;
                continue;
            } else cnt++;
        }
        if(cnt!=0) st.push(s.substr(n-cnt, cnt));
        
        s.erase();
        if(!st.empty()) {
            s=st.top();
            st.pop();
        }
        while(!st.empty()) {
            s+=" "+st.top();
            st.pop();
        }
    }
};
