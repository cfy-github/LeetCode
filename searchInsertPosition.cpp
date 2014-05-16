class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin=0;
        int end=n-1;
        int mid;
        while(begin<end) {
            mid=(end+begin)/2;
            if(A[mid]==target) return mid;
            else if(A[mid]>target) end=mid-1;
            else begin = mid+1;
        }
        if(target<=A[begin]) return begin;
        else if(target>A[begin]) return begin+1;
    }
};
