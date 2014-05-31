class Solution {
public:
    int trap(int A[], int n) {
        int sum1=0, sum2=0;
        int begin=0, end=n-1;
        while(A[begin]==0) begin++;
        while(A[end]==0) end--;
        int pre=0;
        while(begin<end) {
            if(A[begin]<A[end]) {
                sum2+=A[begin];
                if(pre<A[begin]) {
                    sum1+=(A[begin]-pre)*(end-begin+1);
                    pre=A[begin];
                }
                if(pre>=A[end]) {
                    sum2+=A[end];
                    end--;
                }
                begin++;
            } else if(A[begin]>A[end]) {
                sum2+=A[end];
                if(pre<A[end]) {
                    sum1+=(A[end]-pre)*(end-begin+1);
                    pre=A[end];
                }
                if(pre>=A[begin]) {
                    sum2+=A[begin];
                    begin++;
                }
                end--;
            } else {
                sum2+=A[begin]+A[end];
                if(pre<A[end]) {
                    sum1+=(A[end]-pre)*(end-begin+1);
                    pre=A[end];
                }
                begin++;
                end--;
            }
        }
        if(begin==end) {
            sum2+=A[begin];
            if(pre<A[begin]) sum1+=(A[begin]-pre);
        }
        return sum1-sum2;
    }
};
