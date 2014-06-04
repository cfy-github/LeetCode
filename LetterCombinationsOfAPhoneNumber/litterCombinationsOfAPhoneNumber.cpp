class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> r;
        set<string> st;
        string str;
        if(n==0) {
            r.push_back(str);
            return r;
        }
        for(int i=0;i<n;i++) {
            if(digits[i]-'0'==7||digits[i]-'0'==9) {
                for(int j=0;j<4;j++) {
                    str+=(j+parse(digits[i]));
                    dfs(digits, i+1, str, st);
                    str.erase(str.size()-1);
                }
            } else {
                for(int j=0;j<3;j++) {
                    str+=(j+parse(digits[i]));
                    dfs(digits, i+1, str, st);
                    str.erase(str.size()-1);
                }
            }
        }
        copy(st.begin(),st.end(),back_inserter(r));
        return r;
    }
    void dfs(string &digits, int first, string &str, set<string> &st) {
        if(str.size()==digits.size()) {
            st.insert(str);
            return;
        }
        for(int i=first;i<digits.size();i++) {
            if(digits[i]-'0'==7||digits[i]-'0'==9) {
                for(int j=0;j<4;j++) {
                    str+=(j+parse(digits[i]));
                    dfs(digits, i+1, str, st);
                    str.erase(str.size()-1);
                }
            } else {
                for(int j=0;j<3;j++) {
                    str+=(j+parse(digits[i]));
                    dfs(digits, i+1, str, st);
                    str.erase(str.size()-1);
                }
            }
        }
    }
    inline char parse(char d) {
        switch(d) {
            case '2': return 'a';
            case '3': return 'd';
            case '4': return 'g';
            case '5': return 'j';
            case '6': return 'm';
            case '7': return 'p';
            case '8': return 't';
            case '9': return 'w';
            default: return ' ';
        }
    } 
};
