class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        
        vector<vector<int> > r;
        set<vector<int> > s;
        int n=num.size();
        if(n<3) return r;
        
        for(int a=0;a<n-2;++a) {
            int b=a+1, c=n-1;
            if(num[a]==num[c]) {
                if(num[a]==0) s.insert(vector<int> {0,0,0});
                break;
            }
            while(b<c) {
                int sum=num[a]+num[b]+num[c];
                if(num[b]==num[c]) {
                    if(sum==0) s.insert(vector<int> {num[a],num[b],num[c]});
                    break;
                } else {
                    if(sum==0) {
                        s.insert(vector<int> {num[a],num[b],num[c]});
                        while(num[b+1]==num[b]) b++;
                        while(num[c-1]==num[c]) c--;
                        b++;c--;
                    } else if(sum<0) {
                        while(num[b+1]==num[b]) b++;
                        b++;
                    } else {
                        while(num[c-1]==num[c]) c--;
                        c--;
                    }
                }
            }
        }
        copy(s.begin(), s.end(), back_inserter(r));
        return r;
    }
};
