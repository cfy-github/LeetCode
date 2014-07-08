class Solution {
public:
    int trap(int A[], int n) {
        int r=0;
        int max_l=0, max_r=0;
        int left=0, right=n-1;
        int dif=0;
        while(left<right) {
            if(max_l>max_r) {
                dif=max_r-A[right];
                if(dif>0) r+=dif;
                else max_r=A[right];
                right--;
            }
            else {
                dif=max_l-A[left];
                if(dif>0) r+=dif;
                else max_l=A[left];
                left++;
            }
        }
        if(left==right) {
            dif=min(max_r,max_l)-A[left];
            r+=(dif>0?dif:0);
        }
        return r;
    }
};
