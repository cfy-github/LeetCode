class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int tmp;
        int cnt=0;
        int tnc=0;
        while(cnt+tnc<n) {
            if(A[tnc]==elem) {
                tmp=A[n-1-cnt];
                A[n-1-cnt]=A[tnc];
                A[tnc]=tmp;
                cnt++;
            } else {
                tnc++;
            }
        }
        return tnc;
    }
};
