class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        int i=0;
        stack<char> st;
        st.push('#');
        while(!st.empty()&&i<len) {
            char ch=st.top();
            if(s[i]=='('||s[i]=='{'||s[i]=='[') {
                st.push(s[i]);
            } else {
                if(!match(ch,s[i])) return false;
                else st.pop();
            }
            i++;
        }
        if(st.top()!='#') return false;
        else return true;
    }
    inline bool match(char c1, char c2) {
        return abs(c1-c2)==1 || abs(c1-c2)==2;
    }
};
