class Solution {
public:
    int search(int A[], int n, int target) {
        int begin=0,end=n;
        while(begin!=end) {
            int mid=(begin+end)/2;
            if(A[mid]==target) return mid;
            else if(A[begin]<A[mid]) {
                if(target>=A[begin]&&target<A[mid]) end=mid;
                else begin=mid+1;
            } else {
                if(A[mid]<target&&target<=A[end-1]) begin=mid+1;
                else end=mid;
            }
        }
        return -1;
    }
};
