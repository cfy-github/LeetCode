class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > r;
        if(num.size()<3) return r; 
        sort(num.begin(),num.end());
        
        for(int a=0;a<num.size()-2;++a) {
            int b=a+1, c=num.size()-1;
            if(num[a]==num[c]) {
                if(num[a]==0) r.push_back(vector<int> {0,0,0});
                break;
            }
            while(b<c) {
                int sum=num[a]+num[b]+num[c];
                if(num[b]==num[c]) {
                    if(sum==0) r.push_back(vector<int> {num[a],num[b],num[b]});
                    break;
                }
                if(sum==0) {
                    r.push_back(vector<int> {num[a],num[b],num[c]});
                    while(num[b]==num[++b]);
                    while(num[c]==num[--c]);
                } else if(sum<0) while(num[b]==num[++b]);
                else while(num[c]==num[--c]);
            }
            while(num[a]==num[a+1]) a++;
        }
        return r;
    }
};
