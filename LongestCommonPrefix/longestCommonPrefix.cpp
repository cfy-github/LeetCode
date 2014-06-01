class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string str;
        int n=strs.size();
        if(n==0) return str;
        str=strs[0];
        for(int i=1;i<n;i++) {
            str=commonPrefix(str,strs[i]);
        }
        return str;
    }
    inline string commonPrefix(string &str, string &strNew) {
        string r;
        int n1=str.size();
        int n2=strNew.size();
        int n=min(n1,n2);
        for(int i=0;i<n;i++) {
            if(str[i]!=strNew[i]) break;
            r+=str[i];
        }
        return r;
    }
};
