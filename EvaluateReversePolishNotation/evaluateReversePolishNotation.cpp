class Solution {
public:
    inline bool isOp(string s) {
        return s.size()==1 && s[0]=='-'||s[0]=='+'||s[0]=='*'||s[0]=='/';
    }
    inline int doOp(int a, int b, string s) {
        if(s[0]=='+') return a+b;
        else if(s[0]=='-') return a-b;
        else if(s[0]=='/') return a/b;
        else if(s[0]=='*') return a*b;
        else return 0;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(auto s:tokens) {
            if(isOp(s)) {
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                st.push(doOp(a,b,s));
            } else st.push(stoi(s,nullptr,10));
        }
        return st.top();
    }
};
