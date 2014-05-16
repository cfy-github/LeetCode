class Solution {
public:
    int maxSubArray(int A[], int n) {
        int s=0;
        int max=INT_MIN;
        for(int i=0;i<n;i++) {
            s=(s+A[i]>A[i])?s+A[i]:A[i];
            max=(max>s)?max:s;
        }
        return max;
    }
};
