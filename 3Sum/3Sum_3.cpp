class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > r;
        if(num.size()<3) return r; 
        sort(num.begin(),num.end());
        
        auto last=num.end();
        for(auto a=num.begin(); a<prev(last,2); ++a) {
            auto b=next(a), c=prev(last);
            if(*a==*c) {
                if(*a==0) r.push_back(vector<int> {0,0,0});
                break;
            }
            while(b<c) {
                int sum=*a+*b+*c;
                if(*b==*c) {
                    if(sum==0) r.push_back(vector<int> {*a,*b,*c});
                    break;
                }
                if(sum==0) {
                    r.push_back(vector<int> {*a,*b,*c});
                    while(*b==*(++b));
                    while(*c==*(--c));
                } else if(sum<0) while(*b==*(++b));
                else while(*c==*(--c));
            }
            while(*a==*(a+1)) a++;
        }
        return r;
    }
};
