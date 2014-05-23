class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=1) return;
        int r=0, b=n-1, curr=0;
        int tmp;
        while(curr<=b) {
            if(A[curr]==0) {
                tmp=A[r];
                A[r]=A[curr];
                A[curr]=tmp;
                r++;
                curr++;
            }else if(A[curr]==1) {
                //Do Nothing
                curr++;
            } else {
                tmp=A[b];
                A[b]=A[curr];
                A[curr]=tmp;
                b--;
            }
        }
    }
};
