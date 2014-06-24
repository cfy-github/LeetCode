class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        
        int index=0, cnt=1;
        for(int i=1;i<n;++i) {
            if(A[index]!=A[i]) {
                A[++index]=A[i];
                cnt=1;
            } else {
                if(cnt<2) {
                    cnt++;
                    A[++index]=A[i];
                }
            }
        }
        return index+1;
    }
};
