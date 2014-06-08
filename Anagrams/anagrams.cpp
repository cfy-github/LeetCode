class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> r;
        unordered_map<string, vector<string> > group;
        for(auto &s:strs) {
            string key=s;
            sort(key.begin(),key.end());
            group[key].push_back(s);
        }
        for(auto it=group.cbegin();it!=group.cend();++it) {
            if(it->second.size()>1) {
                r.insert(r.end(),it->second.begin(),it->second.end());
            }
        }
        return r;
    }
};
