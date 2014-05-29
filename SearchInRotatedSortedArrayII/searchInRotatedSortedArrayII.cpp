class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin=0, end=n;
        while(begin!=end) {
            int mid=(begin+end)/2;
            if(A[mid]==target) return true;
            else if(A[mid]>A[begin]) {
                if(A[begin]<=target && target<A[mid]) end=mid;
                else begin=mid+1;
            } else if(A[mid]<A[begin]){
                if(A[mid]<target && target<=A[end-1]) begin=mid+1;
                else end=mid;
            } else {
                begin++;
            }
        }
        return false;
    }
};
