class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> r;
        unordered_multimap<int, int> m;
        for(int i=0;i<numbers.size();++i) m.insert(make_pair(numbers[i],i));
        for(int i=0;i<numbers.size();++i) {
            auto it=m.find(target-numbers[i]);
            size_t cnt=m.count(target-numbers[i]);
            if(target-numbers[i]==numbers[i]) {
                if(cnt>1) return vector<int> {1+i, 1+it->second};
            }else if(cnt) return vector<int> {1+i, 1+it->second};
        }
        return r;
    }
};
