class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > r;
        if(num.size()<4) return r;
        int n=num.size();
        sort(num.begin(),num.end());
        int flag=0;
        for(int first=0;first<n-3;first++) {
            for(int last=n-1;last-first>2;last--) {
                 if(num[last]==num[first]) {
                     if(4*num[last]==target) r.push_back(vector<int>(4, num[last]));
                     break;
                 }
                 int t=num[first]+num[last];
                 for(int a=first+1,b=last-1;a<b;) {
                     int tmp=t+num[a]+num[b];
                     if(num[a]==num[b]) {
                         if(tmp==target) r.push_back(vector<int>{num[first],num[a],num[b],num[last]});
                         break;
                     } else {
                         if(tmp==target) {
                             while(num[a+1]==num[a]) a++;
                             while(num[b-1]==num[b]) b--;
                             r.push_back(vector<int>{num[first],num[a],num[b],num[last]});
                             if(b-a>2) {++a;--b;}
                             else break;
                         } else if(tmp>target) {
                             while(num[b-1]==num[b]) b--;
                             --b;
                         } else {
                             while(num[a+1]==num[a]) a++;
                             ++a;
                         }
                     }
                 }
            }
        }
        sort(r.begin(),r.end());
        r.erase(unique(r.begin(),r.end()),r.end());
        return r;
    }
};
