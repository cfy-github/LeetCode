class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n=num.size();
        if(n==0&&n==1) return;
        //int pre=num[n-1];
        int i=n-2;
        for(;i>=0;--i) if(num[i]<num[i+1]) break;
        if(i<0) {
            reverse(num.begin(),num.end());
            return;
        }
        int j;
        for(j=i+1;j<n;j++) if(num[i]>=num[j]) break;
        swap(num[i],num[j-1]);
        reverse(next(num.begin(),i+1),num.end());
    }
};
