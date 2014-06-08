class Solution {
public:
struct mycomp{
    bool operator() (int a, int b) {return a>b;}
}comp;
    int firstMissingPositive(int A[], int n) {
        vector<int> v(A, A+n);
        int pre=0;
        make_heap(v.begin(),v.end(),comp);
        while(!v.empty()) {
            if(v.front()<=0) {
                pop_heap(v.begin(),v.end(),comp);
                v.pop_back();
            } else {
                if(v.front()!=pre&&v.front()!=pre+1) return pre+1;
                else {
                    if(v.front()!=pre) pre++;
                    pop_heap(v.begin(),v.end(),comp);
                    v.pop_back();
                }
            }
        }
        return pre+1;
    }
};
