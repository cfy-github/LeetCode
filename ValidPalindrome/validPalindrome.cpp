class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n==0) return true;
        for(auto head=s.begin(), tail=prev(s.end());head<tail;) {
            if(!isalnum(*head)) {head++; continue;}
            if(!isalnum(*tail)) {tail--; continue;}
            if(tolower(*head)==tolower(*tail)) {head++;tail--;}
            else return false;
        }
        return true;
    }
};
