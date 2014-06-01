class Solution {
public:
    bool canJump(int A[], int n) {
        for(int i=n-2;i>=0;--i) {
            if(A[i]==0) {
                int j=i-1;
                while(j>=0 && A[j]<=(i-j)) j--;
                if(j<0) return false;
                i=j;
            }
        }
        return true;
    }
};
