class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> r;
        generateParenthesis(&r, &curr, 0, n);
        return r;
    }
    void generateParenthesis(vector<string> *v, string *str, int ln, int n) {
        if(n==0) (*v).push_back(*str);
        else {
            if(ln==0) {
                (*str)+="(";
                generateParenthesis(v,str,ln+1,n);
                (*str).erase((*str).end()-1);
            } else if(ln==n) {
                (*str)+=")";
                generateParenthesis(v,str,ln-1,n-1);
                (*str).erase((*str).end()-1);
            } else {
                (*str)+="(";
                generateParenthesis(v,str,ln+1,n);
                (*str).erase((*str).end()-1);
                (*str)+=")";
                generateParenthesis(v,str,ln-1,n-1);
                (*str).erase((*str).end()-1);
            }
        }
    }
};
