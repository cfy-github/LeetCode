class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > r;
        
        auto isNext = [&] (const string &s, const string &n) {
            int cnt=0;
            for(int i=0;i<s.size();++i) if(s[i]!=n[i]) cnt++;
            return cnt==1;
        };
        
        if(isNext(start,end)) {
            r.push_back(vector<string> {start, end});
            return r;
        }
        
        auto genNext = [&] (const string &s) {
            vector<string> r;
            string dup=s;
            for(int i=0;i<s.size();++i) {
                for(char c='a';c<='z';++c) {
                    if(c==dup[i]) continue;
                
                    swap(c, dup[i]);
                    if(dict.find(dup)!=dict.end()) r.push_back(dup);
                    swap(c,dup[i]);
                }
            }
            return r;
        };
        
        unordered_map<string, unordered_set<string> > father;
        
        unordered_set<string> current, next;
        current.insert(start);
        bool fin=false;
        
        while(!current.empty() && !fin) {
            for(const auto &s:current) dict.erase(s);
            for(const auto &s:current) {
                vector<string> new_states=genNext(s);
                for(const auto &next_s:new_states) {
                    father[next_s].insert(s);
                    next.insert(next_s);
                    if(isNext(next_s, end)) {
                        fin=true;
                        father[end].insert(next_s);
                    }
                }
            }
            current.clear();
            swap(current, next);
        }
        
        vector<string> v;
        genPaths(v, r, father, start, end);
        return r;
    }
private:   
    void genPaths(vector<string> &path, vector<vector<string> > &r,
        unordered_map<string, unordered_set<string> > &father, const string &start, const string &end) {
            path.push_back(end);
            if(end==start) {
                r.push_back(path);
                reverse(r.back().begin(), r.back().end());
            } else {
                for(const auto &f:father[end]) genPaths(path, r, father, start, f);
            }
            path.pop_back();
        }
};
