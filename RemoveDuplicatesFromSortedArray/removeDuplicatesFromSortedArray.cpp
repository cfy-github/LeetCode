class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1) return n;
        int curr=0;
        int next=1;
        while(next<n) {
            if(A[next]!=A[curr]) A[++curr]=A[next];
            next++;
        }
        return curr+1;
    }
};
