class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        for(size_t i=0;i<num.size();++i) s.insert(num[i]);
        int r=0;
        for(size_t k=0;k<num.size();++k) {
            if(!s.count(num[k])) continue;
            s.erase(num[k]);
            int len=1;
            for(int i=1;s.count(num[k]+i);++i,++len) s.erase(num[k]+i);
            for(int i=1;s.count(num[k]-i);++i,++len) s.erase(num[k]-i);
            r=max(r,len);
        }
        return r;
    }
};
