class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
       int min_gap=INT_MAX;
       sort(num.begin(),num.end());
       int r=0;
       auto last=num.end();
       for(auto a=num.begin();a<prev(last, 2);++a) {
           auto b=next(a), c=prev(last);
           while(b<c) {
               int sum=*a+*b+*c;
               int gap=sum-target;
               if(gap==0) return target;
               else if(gap<0) b++;
               else c--;
               
               if(abs(gap)<min_gap) {r=sum; min_gap=abs(gap);}
           }
       }
       return r;
    }
};
