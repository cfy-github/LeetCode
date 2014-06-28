class Solution {
public:
    void nextPermutation(vector<int> &num) {
        nextPermutation(num.begin(), num.end());
    }
    void nextPermutation(vector<int>::iterator it0, vector<int>::iterator itn) {
        if(distance(it0, itn)<2) return;
        auto curr=prev(itn);
        while(curr>it0 && *curr<=*(--curr));
        if(*curr>=*(curr+1)) {
            reverse(it0, itn);
            return;
        }
        auto tmp=curr;
        while(tmp+1<itn && *curr<*(tmp+1)) tmp++;
        swap(*tmp, *curr);
        reverse(next(curr), itn);
    }
};
