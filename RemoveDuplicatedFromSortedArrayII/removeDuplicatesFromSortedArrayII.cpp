class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int pre=A[0];
        int cnt=2;
        int curr=0;
        for(int i=0;i<n;i++) {
            if(A[i]==pre) {
                if(cnt==0) continue;
                else {
                    if(curr!=i) A[curr]=A[i];
                    curr++;
                    cnt--;
                }
            } else {
                pre=A[i];
                cnt=1;
                if(curr!=i) {
                    A[curr]=A[i];
                }
                curr++;
            }
        }
        return curr;
    }
};
