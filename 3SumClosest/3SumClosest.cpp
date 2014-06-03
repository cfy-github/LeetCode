class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int min_gap=INT_MAX;
        int r=0;
        sort(num.begin(),num.end());
        for(auto a=num.begin();a!=prev(num.end(),2);++a) {
            auto b=next(a);
            auto c=prev(num.end());
            while(b<c) {
                int sum=*a+*b+*c;
                int gap=abs(sum-target);
                if(gap<min_gap) {
                    min_gap=gap;
                    r=sum;
                }
                if(sum==target) return sum;
                else if(sum>target) --c;
                else ++b;
            }
        }
        return r;
    }
};
