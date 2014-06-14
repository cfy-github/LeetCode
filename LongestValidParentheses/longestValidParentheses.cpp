class Solution {
public:
    int longestValidParentheses(string s) {
        int r=0, last=-1;
        stack<int> st;
        int i=0;
        while(i<s.size()) {
            if(s[i]=='(') {
                st.push(i);
            } else {
                if(st.empty()) {
                    last=i;
                } else {
                    st.pop();
                    if(st.empty()) {
                        r=max(r, i-last);
                    } else {
                        r=max(r, i-st.top());
                    }
                }
            }
            i++;
        }
        return r;
    }
};
