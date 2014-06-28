class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > r;
        if(num.size()<4) return r;
        sort(num.begin(), num.end());
        auto last=num.end();
        for(auto a=num.begin();a<prev(last,3);++a) {
            if(*a==*(last-1)) {
                if(target==(*a)*4) r.push_back(vector<int> {*a, *a, *a, *a});
                break;
            }
            for(auto b=next(a);b<prev(last,2);++b) {
                auto c=next(b), d=prev(last);
                if(*b==*d) {
                    if(*a+(*b)*3==target) r.push_back(vector<int> {*a, *b, *b, *b});
                    break;
                }
                while(c<d) {
                    int sum=*a+*b+*c+*d;
                    if(*c==*d) {
                        if(sum==target) r.push_back(vector<int> {*a, *b, *c, *c});
                        break;
                    }
                    if(sum==target) {
                        r.push_back(vector<int> {*a, *b, *c, *d});
                        while(*c==*(++c));
                        while(*d==*(--d));
                    } else if(sum<target) while(*c==*(++c));
                    else while(*d==*(--d));
                }
                while(*b==*(b+1)) ++b;
            }
            while(*a==*(a+1)) ++a;
        }
        return r;
    }
};
