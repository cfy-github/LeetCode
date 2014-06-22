class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len=m+n;
        if(len==0) return 0.0;
        
        if(len & 1) {
            return findKth(A, m, B, n, len/2+1);
        } else {
            return (findKth(A, m, B, n, len/2)+findKth(A, m, B, n, len/2+1))/2.0;
        }
    }
    double findKth(int A[], int m, int B[], int n, int k) {
        if(m<n) return findKth(B, n, A, m, k);
        if(n==0) return A[k-1];
        if(k<2) return min(A[0],B[0]);
        int ib=min(n, k/2), ia=k-ib;
        if(A[ia-1]==B[ib-1]) return A[ia-1];
        else if(A[ia-1]<B[ib-1]) {
            return findKth(A+ia, m-ia, B, n, k-ia);
        } else return findKth(A, m, B+ib, n-ib, k-ib);
    }
};
