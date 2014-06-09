class Solution {
public:
    int sqrt(int x) {
        //if(x<2) return x;
        int left=1, right=x/2;
        int old_mid=x;
        while(left<=right) {
            const int mid=left+(right-left)/2;
            if(x/mid>mid) {
                left=mid+1;
                old_mid=mid;
            } else if(x/mid<mid) {
                right=mid-1;
            } else return mid;
        }
        return old_mid;
    }
};
