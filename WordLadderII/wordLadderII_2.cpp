class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> current, next;
        unordered_map<string, vector<string> > father;
        bool found = false;
        auto state_is_target = [&](const string &s) {return s == end;};
        auto state_extend = [&](const string &s) {
            unordered_set<string> result;
            for (size_t i = 0; i < s.size(); ++i) {
                string new_word(s);
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == new_word[i]) continue;
                    
                    swap(c, new_word[i]);
                    if (dict.count(new_word) > 0 || new_word == end) result.insert(new_word);
                    swap(c, new_word[i]);
                }
            }
            return result;
        };
        current.insert(start);
        while (!current.empty() && !found) {
            for(const auto &word:current) dict.erase(word);
            for (const auto& word : current) {
                const auto new_states = state_extend(word);
                for (const auto &state : new_states) {
                    if (state_is_target(state)) found = true;
                    next.insert(state);
                    father[state].push_back(word);
                }
            }
            current.clear();
            swap(current, next);
        }
        vector<vector<string> > result;
        if (found) {
            vector<string> path;
            gen_path(father, path, start, end, result);
        }
        return result;
}
private:   
    void gen_path(unordered_map<string, vector<string> > &father, vector<string> &path,
         const string &start, const string &end, vector<vector<string> > &r) {
            path.push_back(end);
            if(end==start) {
                r.push_back(path);
                reverse(r.back().begin(), r.back().end());
            } else {
                for(const auto &f:father[end]) gen_path(father, path, start, f, r);
            }
            path.pop_back();
        }
};
