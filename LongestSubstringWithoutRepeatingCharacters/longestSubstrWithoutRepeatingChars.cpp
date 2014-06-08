class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int n=s.size();
        if(n<=1) return n;
        int ret=INT_MIN, first=0;
        for(int i=0;i<n;i++) {
            if(last.find(s[i])!=last.end()&&last[s[i]]>=first) {
                ret=max(ret, i-first);
                first=last[s[i]]+1;
            }
            last[s[i]]=i;
        }
        return max(ret, n-first);
    }
};
